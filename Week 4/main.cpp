#include <cstdlib>

#include "Stack.h"

using namespace std;


int main(int argc, char** argv) {
    
    Stack<int> stack {};
    stack.push(*new int {3});
    stack.push(*new int {4});
    
    cout << stack.peek() << endl;
    
    stack.printFromBottom();
    
    stack.pop();
    
    stack.printFromTop();
    
    return 0;
}

