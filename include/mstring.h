#ifndef MSTRING_H
#define MSTRING_H

#include "minimal_string.h" // Use minimal string functions

class MString {
public:
    MString() : data(nullptr), length(0) {}

    MString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    MString(const MString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    ~MString() {
        delete[] data;
    }

    MString& operator=(const MString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    bool operator==(const MString& other) const {
        if (length != other.length) {
            return false;
        }
        return strcmp(data, other.data) == 0;
    }

    const char* c_str() const {
        return data;
    }

    size_t size() const {
        return length;
    }

private:
    char* data;
    size_t length;
};

#endif // MSTRING_H