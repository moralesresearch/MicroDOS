#include "uart.h"

// Base address for UART registers
constexpr unsigned int UART_BASE = 0x3F201000;

// Offsets for UART registers
constexpr unsigned int UART_DR = 0x00;	 // Data Register
constexpr unsigned int UART_FR = 0x18;	 // Flag Register
constexpr unsigned int UART_IBRD = 0x24; // Integer Baud Rate Divisor
constexpr unsigned int UART_FBRD = 0x28; // Fractional Baud Rate Divisor
constexpr unsigned int UART_LCRH = 0x2C; // Line Control Register
constexpr unsigned int UART_CR = 0x30;	 // Control Register
constexpr unsigned int UART_IMSC = 0x38; // Interrupt Mask Set/Clear Register
constexpr unsigned int UART_ICR = 0x44;	 // Interrupt Clear Register

namespace uart
{

	// Memory-mapped I/O access
	volatile unsigned int *uart_base = reinterpret_cast<volatile unsigned int *>(UART_BASE);

	// Helper functions for memory barriers
	static inline void memory_barrier()
	{
		asm volatile("dmb sy" ::: "memory");
	}

	void init()
	{
		uart_base[UART_CR] = 0x00000000;
		memory_barrier();

		uart_base[UART_ICR] = 0x7FF;
		memory_barrier();

		uart_base[UART_IBRD] = 26;
		uart_base[UART_FBRD] = 3;
		memory_barrier();

		uart_base[UART_LCRH] = (1 << 4) | (1 << 5) | (1 << 6);
		memory_barrier();

		uart_base[UART_IMSC] = (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10);
		memory_barrier();

		uart_base[UART_CR] = (1 << 0) | (1 << 8) | (1 << 9);
		memory_barrier();
	}

	void putc(char c)
	{
		while (uart_base[UART_FR] & (1 << 5))
			;
		uart_base[UART_DR] = c;
	}

	void puts(const char *str)
	{
		while (*str)
		{
			putc(*str++);
		}
	}

	char getc()
	{
		while (uart_base[UART_FR] & (1 << 4))
			;
		return uart_base[UART_DR];
	}

	bool is_ready_to_send()
	{
		return !(uart_base[UART_FR] & (1 << 5));
	}

	bool has_received()
	{
		return !(uart_base[UART_FR] & (1 << 4));
	}

} // namespace uart