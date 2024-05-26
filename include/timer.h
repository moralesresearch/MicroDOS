#ifndef TIMER_H
#define TIMER_H

namespace timer
{
	// Initialize the system timer
	void init();

	// Delay for a specified number of milliseconds
	void delay(unsigned int ms);

	// Get the current system time in microseconds
	unsigned long long get_time();
}

#endif // TIMER_H