#include <stddef.h>
#include <librpi3/semaphore.h>
#include <librpi3/uart-mini.h>
#include <librpi3/mmu.h>
#include <librpi3/arm.h>
#include <librpi3/arm-config.h>
#include <librpi3/stdio.h>
#include <librpi3/required.h>
#include <librpi3/vector-table.h>
#include <librpi3/svc.h>
#include <librpi3/bcm2837.h>
#include <librpi3/boot.h>

/*===================================================*/
/* Protocol for triggering function execution on     */
/* the slave cores (Cores 1-3).                      */
/*                                                   */
/* The slave cores will cyclically wait for a        */
/* function address, execute it, and then return to  */
/* waiting state. Synchronization is done through the*/
/* mailbox system - mailbox 3 of each core will be   */
/* used to transmit the function addresses.          */
/*                                                   */
/* The function addresses will usually be done by    */
/* Core 0 (the master core). However, any core       */
/* can do it. For instance, Core 0 can send a        */
/* a function to Core 1, which itself can send a     */
/* function to Core 2.                               */
/* ATTENTION: mailboxes have a little buffering      */
/* capabilities, but not much. It is safe to ensure  */
/* that a new function address is sent only after the*/
/* previous function has completed.                  */
/*---------------------------------------------------*/

// Type of function to execute
typedef void (*calledfun)(void) ;

// Counter for number of cores currently initialized
volatile uint8_t CoreReady[4] ;

/* Function executed by Cores 1-3 to wait for functions 
 * to execute */
__attribute__((noinline,noreturn))
void CoreWait(uint32_t cpuid) {    
  // Inform the master the core is started
  CoreReady[cpuid] = 1 ;
  //uint32_t cpuid = GetCoreID() ;
  uint32_t fun_addr ;
  for(;;) {
    // I need a for loop here, because I may have functions
    // that complete their execution, such as "mmu_init"...
    do {
      asm volatile("wfe") ;
      fun_addr = LOC_PERIPH->MBoxRC[cpuid][3] ;
    } while (fun_addr == 0) ;
    LOC_PERIPH->MBoxRC[cpuid][3] = fun_addr ;
    DMB(sy) ;
    (*((calledfun)(uint64_t)fun_addr))() ;
  }
}

/* Launch the execution of function func on core cpuid,
 * with cpuid\in{1,2,3} */
__attribute__((noinline,optimize("-O0")))
void CoreExecute (uint8_t cpuid, void (*func) (void)) {
  /* Load the address of the function to execute in the 
   * mailbox 3 of the chosen CPU. The mailbox protocol 
   * will do the rest. */
  LOC_PERIPH->MBoxWR[cpuid][3] = (uint32_t)(uint64_t)func ;
  asm volatile("sev":::"memory") ;
  DMB(sy) ;
}




/*===================================================*/
/* */
void enter_el0(void) {
  uint64_t cpuid = GetCoreID() ;
  /* The call branch_el1_to_el0 also positions the first
   * argument to be cpuid */
  branch_el1_to_el0(0x800000,0x900000-cpuid*0x1000) ;  
}


// Semaphore to ensure mutual exclusion between the cores
// when calling MMU init function
semaphore_t mmu_mutex ;
// A synchronizing wrapper around MMU init
void mmu_init_wrapper(void) {
  mmu_init_el1() ;
  /*release the semaphore */
  semaphore_dec(&mmu_mutex);
}

// Recall that when this function is first entered (by
// Core 0), Cores 1-3 are still blocked, waiting for
// a sign to start. This means we are free to initialize
// at our rhythm.
__attribute__((optimize("-O0")))
void el1_main(void) {
  uint64_t cpuid = GetCoreID() ;

  //miniuart_puts("C0:EL1 entered.\n") ;
  
  if(cpuid == 0) {
    // BSS init, which also initializes the global variables
    bss_init() ;
    // MMU page table initialization
    init_page_table_el1();
    miniuart_puts("C0:Page table created.\n") ;
    
    // Bring cores 1-3 to secondary spin. The
    // cores are simply waiting for a memory cell
    // to receive the address of the core entry
    // point (and then for an event to wake them
    // from wfe).
    int core ;
    for(core=1;core<4;core++) {
      SPIN_ADDR[core-1] = (uint64_t)_start ;
      asm volatile("sev") ;
      while(CoreReady[core] == 0) ;
    }

    // Now, starting the MMU on the 4 cores, starting with
    // Core 0
    mmu_init_el1() ;
    miniuart_puts("C0:MMU initialized.\n") ;
    for(core=1;core<4;core++) {
      char buf[64] ;
      semaphore_inc(&mmu_mutex) ;
      snprintf(buf,63,"C0: execute mmu_init on CPU%d...",core) ;
      miniuart_puts_noend(buf) ;
      CoreExecute(core, mmu_init_wrapper);
      miniuart_puts("Done\n") ;
    }
    
    miniuart_puts("C0:=======start=concurrent=execution=======\n") ;

    // Here, start the EL0 execution of the 4 cores
    for(core=1;core<4;core++) {
      CoreExecute(core, enter_el0);
    }
    enter_el0() ;
    
  } else {
    CoreWait(cpuid) ;
  }
}

// This code will use the stack of the loader to
// avoid using another assembly file
void el2_main(void) {
  // Printing buffer
  char buf[128] ;
  uint64_t cpuid = GetCoreID() ;

  // Do it here, in C, instead of using assembly for it
  MaskAllInterrupts() ;
  
  if(cpuid == 0) {
    snprintf(buf,127,"Core 0 entered in EL2.\n") ;
    miniuart_puts(buf) ;
  }
  
  // Configure registers at EL2
  arm_config_el2(VectorTableEL2,NULL) ;
  
  // Configure MMU at EL2
  if(cpuid == 0) {
    init_page_table_el2();
  }
  // Start MMU at EL2
  mmu_init_el2() ;
  
  // Configure SVC environment 
  // svc_init() ;

  if(cpuid == 0) {
    miniuart_puts("Core 0: MMU initialized at EL2.\n") ;
  }
  
  // Set up the stack of EL1 - 512 uint32_t's for each
  // core
  uint32_t* sp ;  
  sp = __end__+((cpuid+1)*512) ;
  
  // Configure the registers of EL1
  arm_config_el1(VectorTableEL1,sp) ;

  if(cpuid == 0) {
    miniuart_puts("Core 0: EL1 stack and registers set from EL2.\n") ;
    miniuart_puts("Core 0: Prepare branch to EL1.\n") ;
  }

  // Set up timer
  arm_timer_config_el2() ;

  // Branch to EL1
  branch_el2_to_el1((uint64_t)el1_main) ;
}

// I must define this constant to satisfy the requirement
// of required.h
__attribute__((noreturn))
void _c_start(void) {
  el2_main() ;
  // Shut up the compiler
  for(;;) ;
}
