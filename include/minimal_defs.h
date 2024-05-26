#ifndef MINIMAL_DEFS_H
#define MINIMAL_DEFS_H

#include <stddef.h>

template <typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair() : first(), second() {} // Default constructor

    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

template <typename T1, typename T2>
Pair<T1, T2> make_pair(const T1& first, const T2& second) {
    return Pair<T1, T2>(first, second);
}

#endif // MINIMAL_DEFS_H