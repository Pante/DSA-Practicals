// List.h - - Specification of List ADT
#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
typedef int ItemType;

class List {
private:
    ItemType items[MAX_SIZE];
    int size;

public:
    List();

    bool add(ItemType item);

    bool add(int index, ItemType item);

    void remove(int index);

    ItemType get(int index);

    bool isEmpty();

    int getLength();

    void print();

    void replace(int index, ItemType item);
};
