#include "List.h"

template <class T> List<T>::List() : size {0}, head {nullptr}, tail {nullptr} {
    
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
        tail = current;
        
    } else if (index == 0){
        head->previous = current;
        current->next = head;
        head = current;
        
    } else if (index == size) {
        tail->next = current;
        current->previous = tail;
        tail = current;
        
    } else if (size / 2 >= index) {
        insertHead(index, current);
        
    } else {
        insertTail(index, current);
    }
    
    size++;
    
    return true;
}

template <class T> void List<T>::insertHead(int index, Node<T>*& current) {
    Node<T>* previous = nullptr;
    Node<T>* next = head;
    
    for (int i = 0; i < index; i++) {
        previous = next;
        next = next->next;
    }
    
    current->previous = previous;
    current->next = next;
    
    previous->next = current;
    next->previous = current;
}

template <class T> void List<T>::insertTail(int index, Node<T>*& current) {
    Node<T>* previous = nullptr;
    Node<T>* next = tail;
    
    for (int i = size; i > index; i--) {
        previous = next;
        next = next->previous;
    } 
    
    current->previous = next;
    current->next = previous;
    
    previous->previous = current;
    next->next = next;
}

template <class T> void List<T>::remove(int index) {
    
}
