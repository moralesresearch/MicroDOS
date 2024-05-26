#ifndef MEMORY_H
#define MEMORY_H

namespace memory
{
	// Initialize memory management
	void init();

	// Simple memory allocation function
	void *alloc(unsigned int size);

	// Simple memory deallocation function
	void free(void *ptr);

	// Zero out a block of memory
	void memset(void *ptr, int value, unsigned int size);
}

#endif // MEMORY_H