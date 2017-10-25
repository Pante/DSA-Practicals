#include <cstdlib>
#include <string>
#include <iostream>
#include <ios>
#include <sstream>

using namespace std;

string input();

void format(const string& value);


int main(int argc, char** argv) {
    cout << "Enter a digit: ";
    format(input());
    
    return 0;
}

string input() {
    int value;
    while (cin >> value) {
        if (cin) {
            return to_string(value);

        } else if (cin.fail()) {
            cout << "Input must be a digit, please try again" << endl;
            cin.clear();

        } else {
            throw runtime_error("An error occurred");
        }
    }
}

void format(const string& value) {
    stringstream stream;
    stream << value[0];
    for (int i = 1; i < value.size(); i++) {
        stream << "   " << value[i];
    }
    
    cout << stream.str();
}

