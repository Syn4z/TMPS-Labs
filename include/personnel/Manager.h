#pragma once

#include "Employee.h"
#include <iostream>

class Manager : public Employee {
public:
    Manager(std::string name, int id, int team_size);
    Employee* Clone() const override;
    void Display() const override;

private:
    int team_size_;
};
