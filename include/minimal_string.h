#ifndef MINIMAL_STRING_H
#define MINIMAL_STRING_H

#include <stddef.h>

size_t strlen(const char* str);
char* strcpy(char* dest, const char* src);
int strcmp(const char* s1, const char* s2);

#endif // MINIMAL_STRING_H