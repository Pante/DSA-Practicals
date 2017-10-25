#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
public:
    Employee();
    Employee(const string& name, const string& surname, int salary);
    Employee(const Employee& orig);
    virtual ~Employee();

    string getName() const;
    void setName(const string& name);

    string getSurname() const;
    void setSurname(const string& surname);

    int getSalary() const;
    void setSalary(int salary);

private:
    string name;
    string surname;
    int salary;

};


#endif /* EMPLOYEE_H */

