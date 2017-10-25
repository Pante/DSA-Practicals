#include "List.h"  // header file

List::List() { size = 0;
}

bool List::add(ItemType item) {
    bool success = size < MAX_SIZE;
    if (success) {
        items[size] = item;
        size++;
    }
    return success;
}

bool List::add(int index, ItemType item) {
    bool success = (index >= 1) && (index <= size + 1) && (size < MAX_SIZE);
    if (success) {
        for (int pos = size; pos >= index; pos--) {
            items[pos] = items[pos - 1];
        }

        items[index - 1] = item;
        size++;
    }
    return success;
}

void List::remove(int index) {
    bool success = (index >= 1) && (index <= size);
    if (success) { 
        for (int fromPosition = index + 1; fromPosition <= size; fromPosition++) {
            items[fromPosition - 2] = items[fromPosition - 1];
        }
        size--; 
    }

}

ItemType List::get(int index) {
    bool success = (index >= 1) && (index <= size);
    if (success)
        return items[index - 1];
    else
        return -1;
}


bool List::isEmpty() {
    return size == 0;
}


int List::getLength() {
    return size;
}


void List::print() {
    for (int i = 1; i <= getLength(); i++)
        cout << get(i) << endl;
}

void List::replace(int index, ItemType item) {
    bool success = index >= 1 && index <= getLength();
    if (success)
        items[index - 1] = item;
}