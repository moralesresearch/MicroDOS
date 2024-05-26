#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

namespace framebuffer
{
	// Initialize the framebuffer
	void init();

	// Draw a pixel
	void draw_pixel(int x, int y, unsigned int color);

	// Clear the screen
	void clear_screen(unsigned int color);
}

#endif // FRAMEBUFFER_H