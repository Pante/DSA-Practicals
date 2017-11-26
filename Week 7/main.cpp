#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


static int comparisons = 0;

namespace iterative {

    int search(int array[], int size, int target) {
        for (int i = 0; i < size; i++) {
            comparisons++;
            if (i == target) {
                return i;

            } else if (i > target) {
                return -1;
            }
        }

        return -1;
    }

    
    int binarySearch(int array[], int size, int target) {
        int first = 0;
        int last = size - 1;

        if (first > last || array[first] > target || array[last] < target) {
            return -1;
        }

        while (first <= last) {
            int pivot = (first + last) / 2;
            int value = array[pivot];
            comparisons++;

            if (value == target) {
                return pivot;

            } else if (value < target) {
                last = pivot - 1;

            } else {
                first = pivot + 1;
            }
        }

        return -1;
    }
}


namespace recursive {
    
    int search(int array[], int size, int target) {
        int index = size - 1;
        
        if (index < 0) {
            return -1;
            
        } else if (array[index] == target) {
            return index;
            
        } else {
            return search(array, index, target);
        }
    }
    
    
    int binarySearch(int array[], int first, int last, int target) {
        if (first > last) {
            return -1;
        }
        
        int pivot = (last - first) / 2;
        int value = array[pivot];
        
        if (value == target) {
            return pivot;
            
        } else if (value < target) {
            return binarySearch(array, first, pivot - 1, target);
            
        } else {
            return binarySearch(array, pivot + 1, last, target);
        }
    }
    
}


void display(string type, int value) {
    cout << type << " search: " << comparisons << endl;
    if (value != -1) {
        cout << "Found" << endl;
        
    } else {
        cout << "Not found" << endl;
    }
    comparisons = 0;
}


int main(int argc, char** argv) {
    int array[1000];
    for (int i = 0, num = 2; i++, num += 2; i < 1000) {
        array[i] = num;
    }
    
    int target;
    
    cin >> target;
    display("Sequential", iterative::search(array, 1000, target));
    
    cin >> target;
    display("Binary", iterative::binarySearch(array, 1000, target));
    
    return 0;
}

