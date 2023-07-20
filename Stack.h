//
//  Stack.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef Stack_h
#define Stack_h

template <typename T>
class Stack {
public:
    ~Stack();

    void push(T data);
    T pop();
    T peek() const;
    bool isEmpty() const { return top == nullptr; }

private:
    struct Node {
        T data;
        Node * next = nullptr;

        Node(T data) : data(data) { }
    };

    Node * top = nullptr;
};

#endif /* Stack_h */
