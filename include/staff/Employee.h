#pragma once

class Employee {
public:
    virtual void work() const = 0;
    virtual void addEmployee(Employee* employee) {}
    virtual ~Employee() = default;
};
