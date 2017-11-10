/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: Karus Labs
 *
 * Created on November 9, 2017, 2:21 PM
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;


template <class T>
struct Node {
    
    Node* previous;
    Node* next;
    T item;
    
    
    Node(T item) : previous {nullptr}, next {nullptr}, item {item} {
        
    }
    
};


template <class T>
class Stack {
    
public:
    Stack();
    ~Stack();
    
    bool isEmpty();
    
    bool push(T& item);
    
    bool pop();
    
    T retrieve(); // Horrible version which even the STL doesn't implement due to the unsafe nature and poor performance of returning by value
    
    T& peek();
    
    void printFromTop();
    
    void printFromBottom();
    
private:
    Node<T>* top;
    Node<T>* bottom;
    int size;
    
};


template <class T> Stack<T>::Stack() : top {nullptr}, bottom {nullptr}, size {0} {}

template <class T> Stack<T>::~Stack() {
    if (size > 0) {
        Node<T>* current = top;
        while (current) {
            Node<T>* previous = current->previous;
            delete current;
            current = previous;
        }
    }
}

template <class T> bool Stack<T>::isEmpty() {
    return size == 0;
}

template <class T> bool Stack<T>::push(T& item) {
    Node<T>* node = new Node<T>(item);
    if (size == 0) {
        top = node;
        bottom = node;
        
    } else if (size == 1) {
        bottom->next = node;
        top = node;
        top->previous = bottom;
        
    } else {
        Node<T>* old = top;
        top = node;
        
        top->previous = old;
        old->next = top;
    }
    
    size++;
    return true;
}

template <class T> bool Stack<T>::pop() {
    if (size == 0) {
        return false;
    }
    
    if (size == 1) {
        delete top;
        top = nullptr;
        bottom == nullptr;
        
    } else if (size == 2) {
        delete top;
        top = bottom;
        top->previous = nullptr;
        top->next = nullptr;
        
    } else {
        Node<T>* node = top->previous;
        delete top;
        top = node;
        top->next = nullptr;
    }
    
    size--;
    return true;
}

template <class T> T Stack<T>::retrieve() {
    if (size == 0) {
        throw out_of_range("Stack is empty");
    } 
    
    T item = top->item;
    if (size == 1) {
        delete top;
        top = nullptr;
        bottom == nullptr;
        
    } else if (size == 2) {
        delete top;
        top = bottom;
        top->previous = nullptr;
        top->next = nullptr;
        
    } else {
        Node<T>* node = top->previous;
        delete top;
        top = node;
        top->next = nullptr;
    }
    
    size--;
    return item;
}

template <class T> T& Stack<T>::peek() {
    if (size > 0) {
        return top->item;
        
    } else {
        throw runtime_error("stack is empty");
    }
}

template <class T> void Stack<T>::printFromBottom() {
    Node<T>* node = bottom;
    while (node) {
        cout << node->item << endl;
        node = node->next;
    }
}

template <class T> void Stack<T>::printFromTop() {
    Node<T>* node = top;
    while (node) {
        cout << node->item << endl;
        node = node->previous;
    }
}

#endif /* STACK_H */

