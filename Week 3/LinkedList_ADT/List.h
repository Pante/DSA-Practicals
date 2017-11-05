#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node {
    
    Node* next;
    Node* previous;
    
    T item;
    
    Node(T item) : next {nullptr}, previous {nullptr}, item {item} {
        
    }
    
};


template <class T>
class List {
public:
    List();
    
    ~List();
    
    bool add(T item);

    bool add(int index, T item);

    void remove(int index);

    T& operator[] (int index);

    bool isEmpty() const;

    int length() const;

    void print() const;    
    
private:
    void insertHead(int index, Node<T>*& current);
    
    void removeHead(int index);
    
    Node<T>* head;
    Node<T>* tail;
    
    int size;
};


template <class T> List<T>::List() : head {nullptr}, tail {nullptr}, size {0} {
    
}

template <class T> List<T>::~List() {
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    while (current != nullptr) {
        previous = current;
        current = current->next;
        delete previous;
    }
}


template <class T> bool List<T>::add(T item) {
    return add(size, item);
}

template <class T> bool List<T>::add(int index, T item) {
    if (index < 0 || index > size) {
        return false;
    }
    
    Node<T>* current = new Node<T> {item};
    if (size == 0) {
        head = current;
        
    } else {
        insertHead(index, current);
    }
    size++;
    
    return true;
}

template <class T> void List<T>::insertHead(int index, Node<T>*& current) {
    Node<T>* previous = head;
    Node<T>* next = nullptr;

    for (int i = 0; i < index; i++) {
        next = previous->next;
    }
    
    current->next = next;
    
    if (previous != nullptr) {
        previous->next = current;
    } else {
        head = current;
    }
    next->previous = current;
}

template <class T> void List<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index of of bounds");
        
    } else if (size == 0) {
        return;
    }
    
    Node<T>* node = nullptr;
    if (size == 1) {
        node = head;
        head = nullptr;
        tail = nullptr;
        
    } else if (size / 2 >= index) {
        node = removeHead(index);
        
    } else {
        node = removeTail(index);
    }
    
    delete node;
    size--;
}



template <class T> T& List<T>::operator[] (int index) {
    if (index < 0 || index > size - 1) {
        throw out_of_range("Index out of bound");
    }
    
    Node<T>* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    
    return node->item;
}


template <class T> bool List<T>::isEmpty() const {
    return size == 0;
}

template <class T> int List<T>::length() const {
    return size;
}


template <class T> void List<T>::print() const {
    Node<T>* node = head;
    while (node != nullptr) {
        cout << node->item << endl;
    }
}

#endif /* LIST_H */

