#include "List.h"
#include "Person.h"


template<class T> List<T>::List() : size {0} {
}

template<class T> bool List<T>::add(T item) {
    bool success = size < MAX_SIZE;
    if (success) {
        items[size] = item;
        size++;
    }
    return success;
}

template<class T> bool List<T>::add(int index, T item) {
    bool success = in_range(index) && (size < MAX_SIZE);
    if (success) {
        for (int pos = size; pos >= index; pos--) {
            items[pos] = items[pos - 1];
        }

        items[index - 1] = item;
        size++;
    }
    return success;
}

template<class T> void List<T>::remove(int index) {
    if (in_range(index)) { 
        for (int fromPosition = index + 1; fromPosition <= size; fromPosition++) {
            items[fromPosition - 2] = items[fromPosition - 1];
        }
        size--; 
    }
}

template<class T> T List<T>::get(int index) {
    if (in_range(index)) {
        return items[index - 1];
        
    } else {
        throw out_of_range("Out of range: " + index);
    } 
}


template<class T> bool List<T>::isEmpty() {
    return size == 0;
}


template<class T> int List<T>::length() {
    return size;
}


template<class T> void List<T>::print() {
    for (int i = 1; i <= size; i++) {
        cout << "[" << i << "] " << get(i) << endl;
    } 
}

template<class T> void List<T>::replace(int index, T item) {
    if (in_range(index)) {
        items[index - 1] = item;
    } 
}

template<class T> T& List<T>::begin() {
    return items[0];
}

template<class T> T& List<T>::end() {
    return items[size];
}

template<class T> const T& List<T>::begin() const {
    return items[0];
}

template<class T> const T& List<T>::end() const {
    return items[size];
}


template<class T> bool List<T>::in_range(int index) {
    return index >= 1 && index <= size;
}

template class List<Person>;