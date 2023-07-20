//
//  List.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef List_h
#define List_h

#include <stdexcept>

template <typename T>

/// Singly linked list.
class List {
private:
    struct Node {
        T data;
        Node * next = nullptr;

        Node(T data) : data(data) { };
    };

public:
    ~List();

    int count() const { return numElements; }
    bool isEmpty() const { return numElements == 0; }

    void push(const T& data);
    void append(const T& data);
    void insert(const T& data, Node * after);
    void insert(const T& data, int index);
    void remove(int index);
    void removeLast() { remove(numElements - 1); }
    void clear();

    T get(int index) const;
    // TODO: T set(int index);

private:
    Node * head = nullptr;
    int numElements = 0;
};


template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::push(const T& data)
{
    Node * node = new Node(data);
    node->next = head;
    head = node;
    ++numElements;
}

template <typename T>
void List<T>::append(const T& data)
{
    Node * newNode = new Node(data);

    if ( isEmpty() ) {
        head = newNode;
    } else {
        Node * n;
        for ( n = head; n->next; n = n->next)
            ;
        n->next = newNode;
    }
    ++numElements;
}

template <typename T>
void List<T>::insert(const T& data, Node * after)
{
    Node * newNode = new Node(data);

    newNode->next = after->next;
    after->next = newNode;
    ++numElements;
}

template <typename T>
void List<T>::clear()
{
    Node * node = head;
    while ( node ) {
        Node * temp = node;
        node = node->next;
        delete temp;
    }

    numElements = 0;
}

template <typename T>
void List<T>::remove(int index)
{
    if ( (unsigned)index >= numElements ) {
        throw std::out_of_range("Index out of range");
    }

    Node * rem;

    if ( index == 0 ) {
        rem = head;
        head = head->next;
    } else {
        Node * node = head;

        int i = 0;
        while ( node && i < index - 1 ) {
            node = node->next;
            i++;
        }

        rem = node->next;
        node->next = rem->next;
    }

    delete rem;
    --numElements;
}

template <typename T>
T List<T>::get(int index) const {
    if ( (unsigned)index >= numElements ) {
        throw std::out_of_range("Index out of bounds");
    }

    Node * n = head;
    int i = 0;
    while ( n && i < index) {
        n = n->next;
        i++;
    }

    if ( n == nullptr ) {
        throw std::out_of_range("Index out of bounds");
    }

    return n->data;
}


#endif /* List_h */
