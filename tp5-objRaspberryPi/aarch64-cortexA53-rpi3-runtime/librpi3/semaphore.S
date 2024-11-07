//"========================================================================="
//	semaphore_inc -- AARCH64 Pi3 code
//	C Function: "void semaphore_inc (uint32_t* sem);"
//	Entry: X0 will have semaphore address value
//	Return: nothing
//"========================================================================="
.section .text.semaphore_inc, "ax", %progbits
.balign	4
.globl semaphore_inc;
.type semaphore_inc, %function
semaphore_inc:
	mov   w2, 1
//	.p2align 2 // DPB: why?
.lockloop:
	ldaxr   w1, [x0]
	stxr    w3, w2, [x0]
	cbnz    w3, .lockloop
	cbnz    w1, .lockloop
	dmb 	ish
	ret
.balign	4
.ltorg
.size	semaphore_inc, .-semaphore_inc

//"========================================================================="
//	semaphore_dec -- Composite Pi1, Pi2 & Pi3 code
//	C Function: "void semaphore_dec (uint32_t* sem);"
//	Entry: X0 will have semaphore address value
//	Return: nothing
//"========================================================================="
.section .text.semaphore_dec, "ax", %progbits
.balign	4
.globl semaphore_dec;
.type semaphore_dec, %function
semaphore_dec:
	stlrb	wzr, [x0]
	dmb 	ish
	ret
.balign	4
.ltorg
.size	semaphore_dec, .-semaphore_dec


//"========================================================================="
//	api_stlr - API access to store release
//"========================================================================="
.section .text.api_stlr, "ax", %progbits
.balign	4
.globl api_stlr;
.type api_stlr, %function
api_stlr:
	stlr	x1, [x0]
	// dmb 	ish
	ret
.balign	4
.ltorg
.size	api_stlr, .-api_stlr
	
//"========================================================================="
//	api_ldar - API access to load acquire
//"========================================================================="
.section .text.api_ldar, "ax", %progbits
.balign	4
.globl api_ldar;
.type api_ldar, %function
api_ldar:
	ldar	x0, [x0]
	// dmb 	ish
	ret
.balign	4
.ltorg
.size	api_ldar, .-api_ldar
	

//"========================================================================="
//	get_sp - obtain the stack pointer
//"========================================================================="
.section .text.get_sp, "ax", %progbits
.balign	4
.globl get_sp;
.type get_sp, %function
get_sp:
	mov	x0, sp
	ret
.balign	4
.ltorg
.size	get_sp, .-get_sp
	

	
