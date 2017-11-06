#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node {
            
    T item;
    Node* next;
    
    Node(T item) : item {item}, next {nullptr} {
        
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
    Node<T>* head;
    int size;
};


template <class T> List<T>::List() : size {0}, head {nullptr} {
    
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
        Node<T>* previous = nullptr;
        Node<T>* next = head;

        for (int i = 0; i < index; i++) {
            previous = next;
            next = next->next;
        }

        current->next = next;

        if (previous == nullptr) {
            head = current;

        } else {
            previous->next = current;
        }
    }
    size++;
    return true;
}


template <class T> void List<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index of of bounds");
        
    } else if (size == 0) {
        return;
    }
    
    if (size == 1) {
        delete head;

    } else {
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

        delete current;
    }
    size--;
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
        node = node->next;
    }
}

#endif /* LIST_H */

