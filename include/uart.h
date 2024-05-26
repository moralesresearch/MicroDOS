#ifndef UART_H
#define UART_H

namespace uart
{
	// Initialize the UART
	void init();

	// Send a character
	void putc(char c);

	// Send a string
	void puts(const char *str);

	// Read a character
	char getc();

	// Check if the UART is ready to send
	bool is_ready_to_send();

	// Check if the UART has received a character
	bool has_received();
}

#endif // UART_H