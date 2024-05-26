#include "minimal_map.h"
#include "mstring.h"
#include "filesystem.h" // Include the necessary header for filesystem::File

template <typename Key, typename Value>
bool MinimalMap<Key, Value>::insert(const Key& key, const Value& value) {
    for (size_t i = 0; i < data.get_size(); ++i) {
        if (data[i].first == key) {
            return false; // Key already exists
        }
    }
    data.push_back(make_pair(key, value));
    return true;
}

template <typename Key, typename Value>
bool MinimalMap<Key, Value>::erase(const Key& key) {
    for (size_t i = 0; i < data.get_size(); ++i) {
        if (data[i].first == key) {
            data.erase(i);
            return true;
        }
    }
    return false;
}

template <typename Key, typename Value>
bool MinimalMap<Key, Value>::find(const Key& key, Value& value) const {
    for (size_t i = 0; i < data.get_size(); ++i) {
        if (data[i].first == key) {
            value = data[i].second;
            return true;
        }
    }
    return false;
}

template <typename Key, typename Value>
bool MinimalMap<Key, Value>::exists(const Key& key) const {
    for (size_t i = 0; i < data.get_size(); ++i) {
        if (data[i].first == key) {
            return true;
        }
    }
    return false;
}

// Explicit template instantiation
template class MinimalMap<MString, filesystem::File>;