/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Karus Labs
 *
 * Created on October 25, 2017, 8:56 PM
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;


const int MAX_SIZE = 100;

template<class T> 
class List {
public:
    List();

    bool add(T item);

    bool add(int index, T item);

    void remove(int index);

    T operator[] (int index);

    bool isEmpty();

    int length();

    void print();

    void replace(int index, T item);
    
    bool in_range(int index);   
    
private:
    T items[MAX_SIZE];
    int size;
    
};

#endif /* LIST_H */

