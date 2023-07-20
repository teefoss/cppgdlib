//
//  Dictionary.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#ifndef Dictionary_h
#define Dictionary_h

#include "List.h"
#include "String.h"
#include <string.h>
#include <stdlib.h>

template <typename T>
class Dictionary {
public:
    Dictionary();

    void insert(const char * key, const T& data);
    bool get(const char * key, T * data);

    void debugPrint() {
        printf("\ntable size: %d\n", tableSize());
        printf("table entries: %d\n", numElements);

        for ( int i = 0; i < tableSize(); i++ ) {
            if ( !table[i].isEmpty() ) {
                printf("list %d\n", i);
                for ( int j = 0; j < table[i].count(); j++ ) {
                    Entry entry = table[i].get(j);
                    printf("  %d: %s, %d\n", j, entry.key, entry.data);
                }
            }
        }
    }

private:
    /*
     Good hash table prime numbers from
     https://planetmath.org/goodhashtableprimes
     Use table size = num table entries * 1.3
     */
    static constexpr int numSizes = 24;
    static constexpr int sizes[numSizes] = {
        193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,
        196613, 393241, 786433, 1572869, 3145739, 6291469,
        12582917, 25165843, 50331653, 100663319, 201326611,
        402653189, 805306457, 1610612741
    };

    int sizeIndex = 0;
    int tableSize() const { return sizes[sizeIndex]; }
    unsigned hash(const char * key) const {
        return String::hash(key) % tableSize();
    }

    struct Entry {
        char * key;
        T data;
    };

    List<Entry> * table;
    int numElements = 0;
};

template <typename T>
Dictionary<T>:: Dictionary()
{
    table = new List<Entry>[tableSize()];
}

template <typename T>
void Dictionary<T>::insert(const char * key, const T& data)
{
    int index = hash(key);
    Entry entry;
    entry.key = strdup(key);
    entry.data = data;

    table[index].push(entry);
    numElements++;

    if ( (float)numElements * 1.3f >= tableSize() ) {
        if ( sizeIndex + 1 < numSizes ) {
            printf("resizing table\n");
            printf("old table:\n");
            debugPrint();

            int oldTableSize = tableSize();
            ++sizeIndex;
            List<Entry> * newTable = new List<Entry>[tableSize()];

            for ( int i = 0; i < oldTableSize; i++ ) {
                for ( int j = 0; j < table[i].count(); j++ ) {
                    Entry entry = table[i].get(j);
                    int newIndex = hash(entry.key);
                    newTable[newIndex].append(entry);
                }
            }

            delete[] table;
            table = newTable;

            printf("new table:\n");
            debugPrint();
        }
    }
}

template <typename T>
bool Dictionary<T>::get(const char * key, T * data)
{
    int index = hash(key);
    for ( int i = 0; i < table[index].count(); i++ ) {
        Entry entry = table[index].get(i);
        if ( strcmp(entry.key, key) == 0 ) {
            *data = entry.data;
            return true;
        }
    }

    return false;
}

#endif /* Dictionary_h */
