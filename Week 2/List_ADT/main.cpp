#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "List.h"
#include "Person.h"

using namespace std;

template<class T> 
using Predicate = bool (*) (T);

template<class T> 
T input(const string& message, const Predicate<T>& predicate = [](T) {return true;}, const string& error_message = "");

void add(List<Person>& contacts);

void remove(List<Person>& contacts);

void find(List<Person>& contacts);


int main(int argc, char** argv) {
    List<Person> contacts {};
    string menu = "---------------- Main Menu -------------------\n"
                  "[1] List the phone numbers\n"
                  "[2] Add a new contact\n"
                  "[3] Remove a contact\n"
                  "[4] Search for a phone number\n"
                  "[0] Exit\n"
                  "----------------------------------------------\n"
                  "Enter your option : \n";
    
    while (true) {
        switch (input<int>(menu, [](int x) {return 0 <= x && x <= 4;}, "Input must be an integer between 0 and 4")) {
            case 1:
                contacts.print();
                break;

            case 2:
                add(contacts);
                break;
                
            case 3:
                remove(contacts);
                break;
                
            case 4:
                find(contacts);
                break;
                
            default:
                return 0;
        }
    }
}

template<class T> 
T input(const string& message, const Predicate<T>& predicate, const string& error_message) {
    cin.exceptions(cin.exceptions() | ios_base::badbit);
    
    T value;
    while (cin >> value) {
        cout << message;
        if (cin && predicate(value)) {
            return value;
            
        } else {
            cin.clear();
            cout << error_message << endl;
        }
    }
}

void add(List<Person>& contacts) {
    string name = input<string>("Enter the person's name");
    string number = to_string(input<int>("Enter the person's phone number"));
    
    contacts.add(Person {name, number});
}

// I was lazy and function pointers only work with non-capturing lambdas.
void remove(List<Person>& contacts) {
    cin.exceptions(cin.exceptions() | ios_base::badbit);
    
    int index;
    while (cin >> index) {
        cout << "Enter the index of the contact to remove: ";
        if (cin && contacts.in_range(index)) {
            contacts.remove(index);
            
        } else {
            cin.clear();
            cout << "Index must be more than 0 and less than or equal to" << contacts.length() << endl;
        }
    }
}

void find(List<Person>& contacts) {
    string name = input<string>("Enter the person's name");
    for (int i = 1; i <= contacts.length();  i++) {
        auto person = contacts[i];
        if (person.getName() == name) {
            cout << person << endl;
            break;
        }
    }
}