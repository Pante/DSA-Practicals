#include <cstdlib>
#include <iostream>

#include "Queue.h"

using namespace std;

int main(int argc, char** argv) {
    Queue<char> queue {};
    
    queue.enqueue(*new char {'a'});
    queue.enqueue(*new char {'b'});
    
    cout << queue.take() << endl;
    
    queue.print();
    
    queue.dequeue();
    queue.print();
    
    return 0;
}

