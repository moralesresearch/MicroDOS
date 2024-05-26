#include "minimal_alloc.h"

// Define a memory pool for allocation
#define MEMORY_POOL_SIZE 1024 * 1024 // 1 MB
static char memory_pool[MEMORY_POOL_SIZE];
static size_t memory_pool_index = 0;

void* operator new(size_t size) {
    return malloc(size);
}

void* operator new[](size_t size) {
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    free(ptr);
}

void operator delete[](void* ptr) noexcept {
    free(ptr);
}

extern "C" void __cxa_pure_virtual() {
    while (1);
}

extern "C" void __cxa_atexit() {
    while (1);
}

void* malloc(size_t size) {
    if (memory_pool_index + size > MEMORY_POOL_SIZE) {
        return nullptr; // Out of memory
    }
    void* ptr = &memory_pool[memory_pool_index];
    memory_pool_index += size;
    return ptr;
}

void free(void* ptr) {
    // In a simple allocator, we may not support free operation.
    // Implementing free requires a more complex memory management system.
}