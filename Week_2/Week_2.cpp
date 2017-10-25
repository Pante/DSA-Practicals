#include "List.h"
#include <iostream>

using namespace std;

int main() {
    List list;
    ItemType item;

    list.add(10);
    list.add(50);
    list.add(2, 30);
    list.add(2, 20);
    list.remove(1);
    list.replace(1, 15);
    for (int i = 1; i <= list.getLength(); i++) {
        item = list.get(i);
        cout << item << endl;
    }
    cout << "===== Using display function =====\n";
    list.print();

    system("PAUSE");
    return 0;
}

