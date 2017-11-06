#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node {
            
    T item;
    
    Node* next;
    Node* previous;
    
    Node(T item) : item {item}, next {nullptr}, previous {nullptr} {
        
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
    
    void insertTail(int index, Node<T>*& current);
    
    Node<T>* removeHead(int index);
    
    Node<T>* removeTail(int index);
    
    Node<T>* head;
    Node<T>* tail;
    
    int size;
};


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
        head->next = current;
        tail->previous = current;
        
    } else if (index <= size / 2) {
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
    
    if (previous != nullptr) {
        previous->next = current;
    } else {
        head = current;
    }
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
    
    if (previous != nullptr) {
        previous->previous = current;
    } else {
        tail = current;
    }
    next->next = next;
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

template <class T> Node<T>* List<T>::removeHead(int index) {
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    
    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }
    
    if (previous != nullptr) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
    
    current->next->previous = previous;
    
    return current;
}

template <class T> Node<T>* List<T>::removeTail(int index) {
    Node<T>* previous = nullptr;
    Node<T>* current = tail;
    
    for (int i = size; i > index; i--) {
        previous = current;
        current = current->previous;
    } 
    
    if (previous != nullptr) {
        previous->previous = current->previous;
    } else {
        tail = current->previous;
    }
    current->previous->next = current;
    
    return current;
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
//        cout << node->item << endl;
        node = node->next;
    }
}

#endif /* LIST_H */

