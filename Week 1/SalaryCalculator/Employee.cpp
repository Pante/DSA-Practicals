#include "Employee.h"
#include<string>



Employee::Employee() {
}

Employee::Employee(const string& name, const string& surname, int salary) : name {name}, surname {surname}, salary {salary} {};

Employee::Employee(const Employee& orig) {
}

Employee::~Employee() {
}


string Employee::getName() const {
    return name;
}

void Employee::setName(const string& name) {
    this->name = name;
}

string Employee::getSurname() const {
    return surname;
}

void Employee::setSurname(const string& surname) {
    this->surname = surname;
}

int Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(int salary) {
    if (salary < 0) {
        salary = 0;
    }
    this->salary = salary;
}

