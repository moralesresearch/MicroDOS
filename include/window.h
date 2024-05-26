#ifndef WINDOW_H
#define WINDOW_H

namespace window
{
	// Initialize windowing system
	void init();

	// Create a window
	void create_window(int x, int y, int width, int height, unsigned int color);

	// Draw a window
	void draw_window(int x, int y, int width, int height, unsigned int color);
}

#endif // WINDOW_H