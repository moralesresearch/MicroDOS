#include "interrupts.h"

// Base address for the interrupt controller
constexpr unsigned int INTERRUPT_BASE = 0x3F00B000;

// Offsets for interrupt registers
constexpr unsigned int IRQ_BASIC_PENDING = 0x200;
constexpr unsigned int IRQ_PENDING1 = 0x204;
constexpr unsigned int IRQ_PENDING2 = 0x208;
constexpr unsigned int FIQ_CONTROL = 0x20C;
constexpr unsigned int ENABLE_IRQS1 = 0x210;
constexpr unsigned int ENABLE_IRQS2 = 0x214;
constexpr unsigned int ENABLE_BASIC_IRQS = 0x218;
constexpr unsigned int DISABLE_IRQS1 = 0x21C;
constexpr unsigned int DISABLE_IRQS2 = 0x220;
constexpr unsigned int DISABLE_BASIC_IRQS = 0x224;

// Memory-mapped I/O access
volatile unsigned int *irq = reinterpret_cast<volatile unsigned int *>(INTERRUPT_BASE);

// Helper functions for memory barriers
static inline void memory_barrier()
{
	asm volatile("dmb sy" ::: "memory");
}

namespace interrupts
{

	void init()
	{
		// Disable all interrupts
		irq[DISABLE_IRQS1] = 0xFFFFFFFF;
		irq[DISABLE_IRQS2] = 0xFFFFFFFF;
		irq[DISABLE_BASIC_IRQS] = 0xFFFFFFFF;
		memory_barrier();
	}

	void enable()
	{
		asm volatile("msr DAIFClr, #2"); // Enable IRQ
	}

	void disable()
	{
		asm volatile("msr DAIFSet, #2"); // Disable IRQ
	}

	void handle_interrupt()
	{
		// Check basic pending IRQs
		unsigned int pending = irq[IRQ_BASIC_PENDING];
		if (pending)
		{
			// Handle specific interrupts here
		}

		// Check pending IRQs in register 1
		pending = irq[IRQ_PENDING1];
		if (pending)
		{
			// Handle specific interrupts here
		}

		// Check pending IRQs in register 2
		pending = irq[IRQ_PENDING2];
		if (pending)
		{
			// Handle specific interrupts here
		}
	}

} // namespace interrupts