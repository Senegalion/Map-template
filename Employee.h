#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    std::string position;
    int age;

    Employee() {
        name = "";
        position = "";
        age = 0;
    }

    Employee(const std::string& name, const std::string& position, int age) {
        this->name = name;
        this->position = position;
        this->age = age;
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Name: " << employee.name 
        << ", Position: " << employee.position 
        << ", Age: " << employee.age;
        return os;
    }
};

#endif
