#include <cstdlib>
#include <iostream>
#include "Employee.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Employee bob {"Bob", "McBobbinson", 100};
    Employee jane {"Jane", "Doe", 10};
    
    cout << "Bob's salary " << bob.getSalary() << " Jane's salary " << jane.getSalary() << endl;
    
    bob.setSalary(bob.getSalary() * 1.1);
    jane.setSalary(jane.getSalary() * 1.1);
    
    cout << "Bob's raised salary " << bob.getSalary() << " Jane's raised salary " << jane.getSalary() << endl;
    
    return 0;
}

