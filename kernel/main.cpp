#include "uart.h"
#include "timer.h"
#include "memory.h"
#include "interrupts.h"
#include "shell.h"
#include "jvm.h"
#include "framebuffer.h"
#include "window.h"
#include "filesystem.h"
#include "process.h"

extern "C" void kernel_main()
{
	// Initialize UART for serial communication
	uart::init();
	uart::puts("Micro Disk Operating System\nversion 1.0R");
	uart::puts("(C) 1983 - 2024 Morales Research Technology Inc.\n");
	uart::puts("Initializing OS...\n");

	// Initialize memory management
	memory::init();
	uart::puts("Memory management initialized.\n");

	// Initialize the timer
	timer::init();
	uart::puts("Timer initialized.\n");

	// Initialize interrupt handling
	interrupts::init();
	uart::puts("Interrupt handling initialized.\n");

	// Enable interrupts
	interrupts::enable();
	uart::puts("Interrupts enabled.\n");

	// Initialize the framebuffer
	framebuffer::init();

	// Initialize the windowing system
	window::init();
	window::create_window(50, 50, 200, 150, 0xFF0000); // Create a red window
	window::create_window(300, 200, 200, 150, 0x00FF00); // Create a green window

	// Initializing filesystem
	filesystem::init();
	uart::puts("Filesystem initialized.\n");

	// Initializing process manager
	process::init();
	uart::puts("Process management initialized.\n");
	// Initialize the JVM
	jvm::init();

	// Initialize the shell
	shell::init();
	uart::puts("Shell initialized. Entering main loop...\n");

	// Run the shell loop
	shell::run();
}