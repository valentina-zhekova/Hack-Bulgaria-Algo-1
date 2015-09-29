#ifndef VECTOR
#define VECTOR

#include <iostream>

template <typename T>
class Vector{
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
    bool insert(int index, T value); // O(n)
    void add(T value); // to end; O(1)
    T get(int index);// return value; O(1)
    bool remove(int index); // O(n)
    void pop(); // remove from last index; O(1)
    int size(); // O(1)
    int capacity(); // Returns the total capacity of the Vector; O(1)
private:
    T* container;
    int length;
    int limit;
    int START_CAPACITY = 20;
    void copy_vector(const Vector& other);
    void double_capacity();
};

// WTF Constructors
template <typename T>
Vector<T>::Vector() {
    length = 0;
    limit = START_CAPACITY;
    container = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
    copyvector(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete [] container;
        copy_vector(other);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    delete [] container;
}

// refactor it!
template <typename T>
void Vector<T>::copy_vector(const Vector& other) {
    length = other.length();
    limit = other.capacity();
    container = new T[limit];
    for (int i = 0; i < length; i++) {
        container[i] = other.get(i);
    }
}

template <typename T>
void Vector<T>::double_capacity() {
    limit *= 2;
    T* temp = new T[limit];
    for (int i = 0; i < length; i++) {
        temp[i] = container[i];
    }
    delete [] container;
    container = temp;
}
// Functions

template <typename T>
bool Vector<T>::insert(int index, T value) {
    bool is_successful = true;
    if (0 <= index && index < length) {
        if (length == limit) {
            double_capacity();
        }
        for (int i = length - 1; i != index; i--) {
            container[i] = container[i-1];
        }
        container[index] = value;
        length++;
    } else {
        is_successful = false;
    }
    return is_successful;
}

template <typename T>
void Vector<T>::add(T value) {
    if (length == capacity) {
        double_capacity();
    }
    container[length] = value;
    length++;
}

// mistake here!!!
template <typename T>
T Vector<T>::get(int index) {
    T result;
   if (0 <= index && index < length) {
        result = container[index];
    } else {
        result = NULL;
    }
    return result;
}

template <typename T>
bool Vector<T>::remove(int index) {
    bool is_successful = true;
    if (0 <= index && index < length) {
        for (int i = index; i < length - 1; i++) {
            container[i] = container[i + 1];
        }
        length--;
    } else {
        is_successful = false;
    }
    return is_successful;
}

template <typename T>
void Vector<T>::pop() {
    length--;
}

template <typename T>
int Vector<T>::size() {
    return length;
}

template <typename T>
int Vector<T>::capacity() {
    return limit;
}

#endif
