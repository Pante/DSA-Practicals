/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.h
 * Author: Karus Labs
 *
 * Created on October 25, 2017, 9:35 PM
 */

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;


class Person {
public:
    Person();
    Person(const string& name, const string& number);
    
    friend ostream& operator<<(ostream& stream, const Person& person);
    
    string getName() const;
    void setName(const string& name);
    
    string getNumber() const;
    void setNumber(const string& number);
    
private:
    string name;
    string number;
   
};

#endif /* PERSON_H */

