#ifndef MVECTOR_H
#define MVECTOR_H

#include <cstddef> // For size_t

template <typename T>
class MVector {
public:
    MVector() : data(nullptr), capacity(0), size(0) {}

    void push_back(const T& value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    void erase(size_t index) {
        if (index >= size) {
            return;
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

private:
    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    T* data;
    size_t capacity;
    size_t size;
};

#endif // MVECTOR_H