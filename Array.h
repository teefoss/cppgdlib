//
//  Array.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef Array_h
#define Array_h



template <typename T, int totalElements>

/// Wrapper for static C array. No index bounds checking is performed
/// during access.
class Array {
public:
    /// Return the number of elements in the array.
    int count() const;

    /// Remove all elements from the array by settings the array count to zero.
    /// Does not clear memory.
    void clear();

    void memset(char fill);

    /// Insert element at end of array.
    void append(const T& data);

    /// Insert element at index. Subsequent elements are shifted right.
    void insert(const T& data, int index);

    /// Remove element at index. Subsequent elements are shifted left.
    void remove(int index);

    /// Remove element quickly. No elements are shifted but the original
    /// order is not preserved.
    void fastRemove(int index);

    const T& operator[](int index) const;
    T& operator[](int index);

    const T * pointer() const;
    T * pointer();

private:
    int numElements = 0;
    T buffer[totalElements];
};



template <typename T, int totalElements>
inline int Array<T, totalElements>::count() const {
    return numElements;
}

template <typename T, int totalElements>
inline void Array<T, totalElements>::clear() {
    numElements = 0;
}

template <typename T, int totalElements>
inline void Array<T, totalElements>::memset(char fill) {
    memset(buffer, fill, sizeof(buffer));
}

template <typename T, int totalElements>
inline void Array<T, totalElements>::append(const T& data) {
    buffer[numElements++] = data;
}

template <typename T, int totalElements>
void Array<T, totalElements>::insert(const T& data, int index) {
    ++numElements;

    for ( int i = numElements - 1; i > index; i-- ) {
        buffer[i] = buffer[i - 1];
    }
}

template <typename T, int totalElements>
void Array<T, totalElements>::remove(int index) {
    // Move everything to the right of index over one.
    for ( int i = index; i < numElements - 1; i++ ) {
        buffer[i] = buffer[i + 1];
    }
    --numElements;
}

template <typename T, int totalElements>
inline void Array<T, totalElements>::fastRemove(int index) {
    buffer[index] = buffer[--numElements];
}

template <typename T, int totalElements>
inline const T& Array<T, totalElements>::operator[](int index) const {
    return buffer[index];
}

template <typename T, int totalElements>
inline T& Array<T, totalElements>::operator[](int index) {
    return buffer[index];
}

template <typename T, int totalElements>
inline const T * Array<T, totalElements>::pointer() const {
    return buffer;
}

template <typename T, int totalElements>
inline T * Array<T, totalElements>::pointer() {
    return buffer;
}

#endif /* Array_h */
