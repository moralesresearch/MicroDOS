#include "framebuffer.h"
#include "uart.h"
#include <stdint.h> // Include for uintptr_t

namespace framebuffer
{

	// Framebuffer configuration structure
	struct FrameBufferInfo
	{
		volatile unsigned int width;
		volatile unsigned int height;
		volatile unsigned int pitch;
		volatile unsigned int isrgb;
		volatile unsigned int *framebuffer;
	};

	// Framebuffer base address (Mailbox communication)
	volatile unsigned int *mailbox = reinterpret_cast<volatile unsigned int *>(0x3F00B880);
	volatile FrameBufferInfo fb_info __attribute__((aligned(16)));

	// Mailbox communication functions
	void mailbox_write(unsigned int channel, unsigned int data)
	{
		while (mailbox[6] & 0x80000000)
			; // Wait until mailbox is not full
		mailbox[8] = data | (channel & 0xF);
	}

	unsigned int mailbox_read(unsigned int channel)
	{
		unsigned int result;
		while (true)
		{
			while (mailbox[6] & 0x40000000)
				; // Wait until mailbox is not empty
			result = mailbox[0];
			if ((result & 0xF) == channel)
			{
				return result & 0xFFFFFFF0;
			}
		}
	}

	void init()
	{
		fb_info.width = 800;
		fb_info.height = 600;
		fb_info.pitch = 0;
		fb_info.isrgb = 1;
		fb_info.framebuffer = 0;

		mailbox_write(1, reinterpret_cast<uintptr_t>(&fb_info) | 0x40000000); // Use uintptr_t for casting pointer
		unsigned int response = mailbox_read(1);

		if (response == 0)
		{
			uart::puts("Framebuffer initialized.\n");
		}
		else
		{
			uart::puts("Framebuffer initialization failed.\n");
		}
	}

	void draw_pixel(int x, int y, unsigned int color)
	{
		volatile unsigned int *fb = fb_info.framebuffer; // Respect volatile qualifier
		unsigned int pitch = fb_info.pitch;
		fb[(y * pitch / 4) + x] = color;
	}

	void clear_screen(unsigned int color)
	{
		volatile unsigned int *fb = fb_info.framebuffer; // Respect volatile qualifier
		unsigned int pitch = fb_info.pitch;
		for (unsigned int y = 0; y < fb_info.height; y++)
		{ // Use unsigned int for loop variable
			for (unsigned int x = 0; x < fb_info.width; x++)
			{ // Use unsigned int for loop variable
				fb[(y * pitch / 4) + x] = color;
			}
		}
	}

} // namespace framebuffer