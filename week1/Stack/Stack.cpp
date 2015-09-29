#ifndef STACK
#define STACK

#include "Queue.cpp"

template <typename T>
class Stack {
public:
    Stack();
    //destructors
    void push(T value); // add to end; O(1)
    T pop(); // return and remove; O(n)
    T peek(); // only return; O(n)
    int size(); // elements in stack; O(1)
private:
    Queue<T> container;
};

template <typename T>
Stack<T>::Stack() {
    container = Stack<T>();
}

template <typename T>
void Stack<T>::push(T value) {
    container.push(value);
}

template <typename T>
T Stack<T>::pop() {
    int length = container.size();
    for (int i = 0; i < size - 1; i++) {
        container.push(container.pop());
    }
    return container.pop();
}

template <typename T>
T Stack<T>::peek() {
    int length = container.size();
    for (int i = 0; i < size - 1; i++) {
        container.push(container.peek());
    }
    return container.peek();
}

template <typename T>
int Stack<T>::size() {
    return container.size();
}

#endif
