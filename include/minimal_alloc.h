#ifndef MINIMAL_ALLOC_H
#define MINIMAL_ALLOC_H

#include <stddef.h>

void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;

extern "C" void __cxa_pure_virtual();
extern "C" void __cxa_atexit();
void* malloc(size_t size);
void free(void* ptr);

#endif // MINIMAL_ALLOC_H