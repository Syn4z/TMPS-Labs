#include "../include/personnel/Employee.h"
#include <iostream>
#include <utility>

Employee::Employee(std::string name, int id, EmployeeType type)
        : name_(std::move(name)), employee_id_(id), employee_type_(type) {}

Employee::~Employee() = default;

void Employee::Display() const {
    std::cout << "Employee Type: ";
    if (employee_type_ == 0) {
        std::cout << "Manager\n";
    } else if (employee_type_ == 1) {
        std::cout << "Developer\n";
    }
    std::cout << "Name: " << name_ << "\n";
    std::cout << "Employee ID: " << employee_id_ << "\n";
}
