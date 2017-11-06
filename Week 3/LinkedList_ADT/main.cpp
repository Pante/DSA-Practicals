#include <cstdlib>
#include <iostream>
#include <string>

#include "List.h"

using namespace std;


int main(int argc, char** argv) {
    List<string> names {};
    cout << names.add("Annie");
    names.add("Jacky");
    names.add("Wendy");
    
    names.print();
    
    names.add(1, "Brenda");
    
    names.print();
    
    names.remove(2);
    
    names.print();
    
    names.remove(0);
    
    names.print();
}

