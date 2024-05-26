#ifndef GPIO_H
#define GPIO_H

namespace gpio
{
	// GPIO pin modes
	enum class PinMode
	{
		Input,
		Output,
		AltFunc0,
		AltFunc1,
		AltFunc2,
		AltFunc3,
		AltFunc4,
		AltFunc5
	};

	// Initialize GPIO
	void init();

	// Set GPIO pin mode
	void set_pin_mode(unsigned int pin, PinMode mode);

	// Write to a GPIO pin
	void write_pin(unsigned int pin, bool value);

	// Read from a GPIO pin
	bool read_pin(unsigned int pin);
}

#endif // GPIO_H