#include "memory.h"

// Declare the symbols defined in the linker script
extern unsigned char _heap_start;
extern unsigned char _heap_end;

static unsigned char *heap_top = &_heap_start;

namespace memory
{

	void init()
	{
		heap_top = &_heap_start;
	}

	void *alloc(unsigned int size)
	{
		size = (size + 7) & ~7; // Align to 8 bytes
		if (heap_top + size > &_heap_end)
		{
			return nullptr; // Out of memory
		}
		void *ptr = heap_top;
		heap_top += size;
		return ptr;
	}

	void free(void *ptr)
	{
		// Simple allocator does not support free
	}

	void memset(void *ptr, int value, unsigned int size)
	{
		unsigned char *p = static_cast<unsigned char *>(ptr);
		for (unsigned int i = 0; i < size; ++i)
		{
			p[i] = static_cast<unsigned char>(value);
		}
	}

} // namespace memory