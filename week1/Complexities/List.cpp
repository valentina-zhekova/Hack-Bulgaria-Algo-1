#ifndef LIST
#define LIST

#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;

    Node<T>(T v=NULL, Node<T>* n=NULL) {
        value = v;
        next = n;
    }
};

template <typename T>
class List {
public:
    List();
    //destructor
    void add(T value); // add to end; O(1)
    T get(int index); // O(n)
    T remove(int index); // O(n)
    bool remove(T value); // O(n)
    int size(); // O(1)
private:
    Node<T> head;
    Node<T> tail;
    int length;
};

template <typename T>
List<T>::List() {
    head = Node<T>();
    tail = Node<T>();
    head.next->
    length = 0;
}

template <typename T>
void List<T>::add(T value) {

}

template <typename T>
T List<T>::get(int index) {

}

template <typename T>
T List<T>::remove(int index) {

}

template <typename T>
bool List<T>::remove(T value) {
}

template <typename T>
int List<T>::size() {

}

#endif
