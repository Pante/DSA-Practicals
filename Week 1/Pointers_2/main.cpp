#include <cstdlib>
#include <iostream>

using namespace std;


void changeValue(int x, int* y);


int main(int argc, char** argv) {
    int x = 30;
    int y = x;

    changeValue(x, &y);
    
    cout << x << endl << y << endl; // x = 30, y = 40
    return 0;
}

void changeValue(int x, int* y) {
    x += 10;
    *y += 10;
}

