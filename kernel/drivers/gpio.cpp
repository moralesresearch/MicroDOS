#include "gpio.h"

namespace gpio
{
	// Base address for GPIO
	constexpr unsigned int GPIO_BASE = 0x3F200000;

	// Offsets for GPIO registers
	constexpr unsigned int GPFSEL0 = 0x00;
	constexpr unsigned int GPFSEL1 = 0x04;
	constexpr unsigned int GPFSEL2 = 0x08;
	constexpr unsigned int GPFSEL3 = 0x0C;
	constexpr unsigned int GPFSEL4 = 0x10;
	constexpr unsigned int GPFSEL5 = 0x14;
	constexpr unsigned int GPSET0 = 0x1C;
	constexpr unsigned int GPSET1 = 0x20;
	constexpr unsigned int GPCLR0 = 0x28;
	constexpr unsigned int GPCLR1 = 0x2C;
	constexpr unsigned int GPLEV0 = 0x34;
	constexpr unsigned int GPLEV1 = 0x38;

	// Memory-mapped I/O access
	volatile unsigned int *gpio = reinterpret_cast<volatile unsigned int *>(GPIO_BASE);

	void init()
	{
		// No special initialization needed for GPIO
	}

	void set_pin_mode(unsigned int pin, PinMode mode)
	{
		unsigned int reg = pin / 10;
		unsigned int shift = (pin % 10) * 3;
		unsigned int mode_bits = 0;

		switch (mode)
		{
		case PinMode::Input:
			mode_bits = 0b000;
			break;
		case PinMode::Output:
			mode_bits = 0b001;
			break;
		case PinMode::AltFunc0:
			mode_bits = 0b100;
			break;
		case PinMode::AltFunc1:
			mode_bits = 0b101;
			break;
		case PinMode::AltFunc2:
			mode_bits = 0b110;
			break;
		case PinMode::AltFunc3:
			mode_bits = 0b111;
			break;
		case PinMode::AltFunc4:
			mode_bits = 0b011;
			break;
		case PinMode::AltFunc5:
			mode_bits = 0b010;
			break;
		}

		gpio[GPFSEL0 + reg] = (gpio[GPFSEL0 + reg] & ~(0b111 << shift)) | (mode_bits << shift);
	}

	void write_pin(unsigned int pin, bool value)
	{
		if (value)
		{
			gpio[GPSET0 + (pin / 32)] = (1 << (pin % 32));
		}
		else
		{
			gpio[GPCLR0 + (pin / 32)] = (1 << (pin % 32));
		}
	}

	bool read_pin(unsigned int pin)
	{
		return (gpio[GPLEV0 + (pin / 32)] & (1 << (pin % 32))) != 0;
	}
}