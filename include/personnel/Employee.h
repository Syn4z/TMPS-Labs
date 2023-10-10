#pragma once

#include <string>

enum EmployeeType {
    MANAGER,
    DEVELOPER
};

class Employee {
public:
    Employee(std::string name, int id, EmployeeType type);
    virtual ~Employee();

    virtual Employee* Clone() const = 0;
    virtual void Display() const;

private:
    std::string name_;
    int employee_id_;
    EmployeeType employee_type_;
};
