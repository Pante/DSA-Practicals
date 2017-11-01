#ifndef LIST_H
#define LIST_H

using namespace std;

template <class T>
struct Node {
    
    Node(T item) : next {nullptr}, previous {nullptr}, item {item} {}
    
    Node* next;
    Node* previous;
    
    T item;
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

    bool isEmpty();

    int length();

    void print();    
    
private:
    void insertHead(int index, Node<T>*& current);
    
    void insertTail(int index, Node<T>*& current);

    Node<T>* head;
    Node<T>* tail;
    
    int size;
};


#endif /* LIST_H */

