.global _start
_start:
	// Initialize the stack, CPU settings, etc.
	ldr x0, =0x80000 // Load the adress of the kernel
	mov sp, x0 // Set the stack pointer
	ldr x0, =kernel_main
	br x0 // Jump to the kernel