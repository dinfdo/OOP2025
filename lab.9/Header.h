#pragma once

#include <iostream>

template<typename KeyType, typename ValueType>
class Map {
private:
    struct Entry {
        KeyType key;
        ValueType value;
        int index;
    };

    Entry* entries;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        Entry* newEntries = new Entry[capacity];
        for (int i = 0; i < count; ++i)
            newEntries[i] = entries[i];
        delete[] entries;
        entries = newEntries;
    }

    int FindIndex(const KeyType& key) const {
        for (int i = 0; i < count; ++i) {
            if (entries[i].key == key)
                return i;
        }
        return -1;
    }

public:
    Map() {
        capacity = 2;
        count = 0;
        entries = new Entry[capacity];
    }

    ~Map() {
        delete[] entries;
    }

    ValueType& operator[](const KeyType& key) {
        for (int i = 0; i < count; ++i)
            if (entries[i].key == key)
                return entries[i].value;

        if (count >= capacity)
            resize();

        entries[count] = { key, ValueType(), count };
        return entries[count++].value;
    }

    const Entry* begin() const { return entries; }
    const Entry* end() const { return entries + count; }

    void set(const KeyType& key, const ValueType& value) {
        for (int i = 0; i < count; ++i)
            if (entries[i].key == key) {
                entries[i].value = value;
                return;
            }

        if (count >= capacity)
            resize();

        entries[count] = { key, value, count };
        ++count;
    }

    bool get(const KeyType& key, ValueType& outValue) const {
        for (int i = 0; i < count; ++i)
            if (entries[i].key == key) {
                outValue = entries[i].value;
                return true;
            }
        return false;
    }

    int size() const {
        return count;
    }

    void clear() {
        delete[] entries;
        capacity = 2;
        count = 0;
        entries = new Entry[capacity];
    }

    bool remove(const KeyType& key) {
        for (int i = 0; i < count; ++i)
            if (entries[i].key == key) {
                for (int j = i; j < count - 1; ++j) {
                    entries[j] = entries[j + 1];
                    entries[j].index = j;
                }
                --count;
                return true;
            }
        return false;
    }

    bool includes(const Map<KeyType, ValueType>& other) const {
        for (int i = 0; i < other.count; ++i) {
            int j = FindIndex(other.entries[i].key);
            if (j == -1 || !(entries[j].value == other.entries[i].value)) {
                return false;
            }
        }
        return true;
    }
};
