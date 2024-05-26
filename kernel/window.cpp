#include "window.h"
#include "framebuffer.h"

namespace window
{

	void init()
	{
		framebuffer::init();
		framebuffer::clear_screen(0x000000); // Clear the screen to black
	}

	void create_window(int x, int y, int width, int height, unsigned int color)
	{
		draw_window(x, y, width, height, color);
	}

	void draw_window(int x, int y, int width, int height, unsigned int color)
	{
		// Draw the window frame
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				framebuffer::draw_pixel(x + j, y + i, color);
			}
		}

		// Draw the window border
		unsigned int border_color = 0xFFFFFF; // White border
		for (int i = 0; i < width; i++)
		{
			framebuffer::draw_pixel(x + i, y, border_color);
			framebuffer::draw_pixel(x + i, y + height - 1, border_color);
		}
		for (int i = 0; i < height; i++)
		{
			framebuffer::draw_pixel(x, y + i, border_color);
			framebuffer::draw_pixel(x + width - 1, y + i, border_color);
		}
	}

} // namespace window