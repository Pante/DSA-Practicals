#include "Person.h"

Person::Person() {
    
}

Person::Person(const string& name, const string& number) : name {name}, number {number} {
    
}

ostream& operator<<(ostream& stream, const Person& person) {  
    stream << "Name: " + person.name << " Number: " + person.number << endl;
    return stream;  
}  

string Person::getName() const {
    return name;
}

void Person::setName(const string& name) {
    this->name = name;
}

string Person::getNumber() const {
    return number;
}

void Person::setNumber(const string& number) {
    this->number = number;
}
