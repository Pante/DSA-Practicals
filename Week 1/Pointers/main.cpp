#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    int value1 = 200000;
    int value2;
    int* ptr;
    ptr = &value1;
    cout << *ptr << endl;
    value2 = *ptr;
    cout << value2 << endl; // prints out the value of value1, 200000
    cout << &value1 << endl;
    cout << ptr << endl; // Same as value1
    ptr = &value2;
    *ptr += 2000;
    cout << value1 << endl << value2 << endl; //value1 = 200000 & value2 = 202000
    
    return 0;
}

