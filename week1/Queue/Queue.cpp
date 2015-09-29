#ifndef QUEUE
#define QUEUE

#include "Vector.cpp"

template <typename T>
class Queue {
public:
    Queue();
    // destructor?
    void push(T value); // to end; O(1)
    T pop(); // return and remove from front; O(1)
    T peek(); // return from front, no remove; O(1)
    int size(); // number of elements; O(1)
private:
    Vector<T> container;
};

template <typename T>
Queue<T>::Queue() {
    container = Vector<T>();
}

template <typename T>
void Queue<T>::push(T value) {
    container.add(value);
}

template <typename T>
T Queue<T>::pop() {
    T result = container.get(0);
    // not possible in O(1)
    container.remove(0);
    return result;
}

template <typename T>
T Queue<T>::peek() {
    return container.get(0);
}

template <typename T>
int Queue<T>::size() {
    return container.size();
}

#endif
