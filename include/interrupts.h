#ifndef INTERRUPTS_H
#define INTERRUPTS_H

namespace interrupts
{
	// Initialize interrupt handling
	void init();

	// Enable interrupts
	void enable();

	// Disable interrupts
	void disable();

	// Interrupt handler function
	void handle_interrupt();
}

#endif // INTERRUPTS_H