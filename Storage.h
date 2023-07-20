//
//  Storage.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef Storage_h
#define Storage_h

#include <new>
#include <stdexcept>

enum ArrayType {
    ARRAY_EXPAND_LINEAR,
    ARRAY_EXPAND_EXPONENTIAL,
    ARRAY_DYNAMIC,
};

template <typename T>

/// Fully dynamic array. Capacity is shrunk only when calling `Insert` or
/// `Append`, and only if the type is `ARRAY_DYNAMIC`.
class Storage {
public:
    Storage(int initialSize = 0,
            ArrayType type = ARRAY_DYNAMIC,
            float growthFactor = 1.0f)
    : type(type), growthFactor(growthFactor) {
        if ( initialSize ) {
            buffer = new T[initialSize];
            capacity = initialSize;
        }

        // TODO: fatal if grow exponential and initial size = 0
    }

    ~Storage() { if ( buffer ) free(buffer); }

    void RemoveAll() { numElements = 0; }
    int Count() const { return numElements; }
    void Insert(const T& data, int index);
    void append(const T& data);
    void remove(int index);
    void removeFast(int index);
    void Resize(int newCapacity) { // in elements
        T * newBuffer = new T[newCapacity];
        memcpy(newBuffer, buffer, capacity);
        capacity = newCapacity;
        delete[] buffer;
        buffer = newBuffer;
    }

    void Erase() { memset(buffer, 0, sizeof(T) * capacity); }

    T& operator[](int index) {
        if ( index + 1 > capacity ) {
            capacity = index + 1;
            Resize(capacity);
        }
        return buffer[index];
    }

    const T& operator[](int index) const {
        if ( index + 1 > capacity ) {
            capacity = index + 1;
            Resize(capacity);
        }
        return buffer[index];
    }

    T * pointer() { return buffer; }
    const T * pointer() const { return buffer; }

private:
    ArrayType type;
    float growthFactor;
    int numElements = 0;
    size_t capacity; // in elements
    T * buffer = nullptr;
};

template <typename T>
void Storage<T>::Insert(const T &data, int index)
{
    if ( (unsigned)index > numElements ) {
        throw std::out_of_range("Index out of bounds");
    }

    ++numElements;

    // Resize?
    if ( numElements > capacity ) {
        if ( type == ARRAY_EXPAND_LINEAR ) {
            capacity += growthFactor;
        } else if ( type == ARRAY_EXPAND_LINEAR ) {
            capacity *= growthFactor;
        } else if ( type == ARRAY_DYNAMIC ) {
            capacity = numElements;
        }

        Resize(capacity);
    }

    // TODO: move all elements over one.

    buffer[index] = data;
}

template <typename T>
void Storage<T>::append(const T& data)
{
    Insert(data, numElements);
}

template <typename T>
void Storage<T>::remove(int index)
{
    if ( (unsigned)index >= numElements ) {
        throw std::out_of_range("Index out of bounds");
    }

    // Most the everything to the right over one to the left.
    for ( int i = index; i < numElements - 1; i++ ) {
        buffer[i] = buffer[i + 1];
    }

    --numElements;
}

template <typename T>
void Storage<T>::removeFast(int index)
{
    if ( (unsigned)index >= numElements ) {
        throw std::out_of_range("Index out of bounds");
    }

    buffer[index] = buffer[--numElements];
}


#endif /* Storage_h */
