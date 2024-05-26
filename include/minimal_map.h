#ifndef MINIMAL_MAP_H
#define MINIMAL_MAP_H

#include "mvector.h"
#include "minimal_defs.h"
#include "mstring.h"

template <typename Key, typename Value>
class MinimalMap {
public:
    bool insert(const Key& key, const Value& value);
    bool erase(const Key& key);
    bool find(const Key& key, Value& value) const;
    bool exists(const Key& key) const;

private:
    MVector<Pair<Key, Value>> data;
};

#endif // MINIMAL_MAP_H