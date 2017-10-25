/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Karus Labs
 *
 * Created on October 25, 2017, 8:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "List.h"
#include "Person.h"

using namespace std;


int select();

int main(int argc, char** argv) {
    List<Person> contacts {};
    while (true) {
        cout << "---------------- Main Menu -------------------" << endl
             << "[1] List the phone numbers" << endl
             << "[2] Add a new contact" << endl
             << "[3] Remove a contact" << endl
             << "[4] Search for a phone number" << endl
             << "[0] Exit" << endl
             << "----------------------------------------------" << endl
             << "Enter your option : ";

        
        switch (select()) {
            case 1:
                contacts.print();
                break;
            
            case 2:
                break;
                
            case 3:
                cout << "Enter contact index to remove: ";
                int index = select();
                if (contacts.in_range(index)) {
                    cout << "Contact removed";
                    contacts.remove(index);
                    
                } else {
                    cout << "Invalid contact index";
                }
                break;
                
            case 4:
                break;
            
            case 0:
                return 0;
                
            default:
                cout << "Invalid input, must be an integer between 0 and 4" << endl;
        }
    }
}

int select() {
    cin.exceptions(cin.exceptions() | ios_base::badbit);
    
    int value;
    while (cin >> value) {
        if (cin) {
            return value;
            
        } else {
            cin.clear();
            cout << "Invalid input, must be an integer between 0 and 4" << endl;
        }
    }
}

