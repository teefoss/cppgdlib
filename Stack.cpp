//
//  Stack.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#include "Stack.h"
#include <stdexcept>

template <typename T>
Stack<T>::~Stack() {
    while ( !isEmpty() ) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node * node = new Node(data);
    node->next = top;
    top = node;
}

template <typename T>
T Stack<T>::pop() {
    if ( isEmpty() ) {
        throw std::out_of_range("Stack is empty");
    }

    T data = top->data;
    Node * temp = top;
    top = top->next;
    delete temp;

    return data;
}

template <typename T>
T Stack<T>::peek() const {
    if ( isEmpty() ) {
        throw std::out_of_range("Stack is empty");
    }

    return top->data;
}
