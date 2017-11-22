#include <algorithm>
#include <cstdlib>
#include <stdexcept>

using namespace std;


long power(int a, int n) {
    if (n < 0) {
        throw out_of_range("n must be a positive integer");
        
    } else if (n == 0) {
        return 1;
    }
    
    if (n == 1) {
        return a;
        
    } else {
        return a * power(a, n - 1);
    }
}

int max_array(const int array[], int n) {
    int index = n - 1;
    if (n < 0) {
        throw out_of_range("array cannot be empty");
    }
    
    if (index == 0) {
        return array[index];
        
    } else {
        return max<int>(array[index], max_array(array, n - 1)); 
    }
}

int main(int argc, char** argv) {
    
    return 0;
}

