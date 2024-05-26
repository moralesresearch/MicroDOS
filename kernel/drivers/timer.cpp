#include "timer.h"

// Base address for the system timer
constexpr unsigned int TIMER_BASE = 0x3F003000;

// Offsets for timer registers
constexpr unsigned int TIMER_CS = 0x00;
constexpr unsigned int TIMER_CLO = 0x04;
constexpr unsigned int TIMER_CHI = 0x08;
constexpr unsigned int TIMER_C0 = 0x0C;
constexpr unsigned int TIMER_C1 = 0x10;
constexpr unsigned int TIMER_C2 = 0x14;
constexpr unsigned int TIMER_C3 = 0x18;

namespace timer
{

	// Memory-mapped I/O access
	volatile unsigned int *timer_base = reinterpret_cast<volatile unsigned int *>(TIMER_BASE);

	void init()
	{
		// Initialization code, if needed
	}

	void delay(unsigned int ms)
	{
		unsigned long long start_time = get_time();
		unsigned long long delay_time = ms * 1000; // Convert milliseconds to microseconds
		while ((get_time() - start_time) < delay_time)
		{
			// Busy wait
		}
	}

	unsigned long long get_time()
	{
		unsigned int chi = timer_base[TIMER_CHI];
		unsigned int clo = timer_base[TIMER_CLO];
		// Ensure chi and clo are read consistently
		if (chi != timer_base[TIMER_CHI])
		{
			chi = timer_base[TIMER_CHI];
			clo = timer_base[TIMER_CLO];
		}
		return (static_cast<unsigned long long>(chi) << 32) | clo;
	}

} // namespace timer