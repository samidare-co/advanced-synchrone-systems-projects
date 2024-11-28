#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdint.h>

// All semaphores must have type semaphore_t.
// This type imposes an alignment that ensures that no
// two semaphores will fall in the same granule. I don't
// really know if this is important, but since I may used
// acquire-release semantics it's better to have it.
//
// The semantics of "Exclusives reservation granule" is
// described in ARMv8 ARM, section B2.9.3, page 141.
typedef __attribute__((aligned(512))) uint32_t semaphore_t ;

// Semaphores start with value 0, which corresponds to the
// "available" status.
// Incrementing them amounts to requesting them. Only one
// can succeed at a time. The call is blocking.
// Decrementing them amounts to giving them.
void semaphore_inc(semaphore_t* sem);
void semaphore_dec(semaphore_t* sem);

// Access to load-acquire and store-release operations
// needed to implement synchronization
void api_stlr(int64_t*addr,const int64_t value) ;
int64_t api_ldar(int64_t*addr) ;

//
uint64_t get_sp(void) ;

#endif
