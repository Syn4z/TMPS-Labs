#pragma once

#include "Employee.h"
#include <string>
#include <vector>

class Supervisor : public Employee {
private:
    std::string name;
    std::vector<Employee*> employees;

public:
    explicit Supervisor(std::string  name);
    void work() const override;
    void addEmployee(Employee* employee) override;
    ~Supervisor() override;
};
