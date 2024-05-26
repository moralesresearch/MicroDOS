#include "shell.h"
#include "uart.h"
#include "timer.h"
#include "memory.h"

int strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

namespace shell
{

	void init()
	{
		uart::puts("ROM DOS Shell 1.0R\n");
		uart::puts("(C) 1979 - 1982 Microsoft Inc.\n");
		uart::puts("(C) 1983 - 2025 Morales Research Technology Inc.\n");
		uart::puts("Type 'help' for a list of commands.\n");
	}

	void run()
	{
		char buffer[256];
		while (true)
		{
			uart::puts("ROM DOS> ");
			int index = 0;
			char c;
			while ((c = uart::getc()) != '\n')
			{
				if (c == '\r')
					continue;
				if (c == '\b' && index > 0)
				{
					uart::puts("\b \b");
					index--;
					continue;
				}
				if (index < sizeof(buffer) - 1)
				{
					buffer[index++] = c;
					uart::putc(c);
				}
			}
			buffer[index] = '\0';
			uart::puts("\n");

			// Simple command parsing
			if (strcmp(buffer, "help") == 0)
			{
				uart::puts("Available commands:\n");
				uart::puts("  help   - Show this help message\n");
				uart::puts("  clear  - Clear the screen\n");
				uart::puts("  reboot - Reboot the system\n");
				// Add more commands as needed
			}
			else if (strcmp(buffer, "clear") == 0)
			{
				uart::puts("\033[2J\033[H");
			}
			else if (strcmp(buffer, "reboot") == 0)
			{
				uart::puts("Rebooting...\n");
				// Trigger a system reboot (this will be hardware specific)
			}
			else
			{
				uart::puts("Unknown command. Type 'help' for a list of commands.\n");
			}
		}
	}

} // namespace shell