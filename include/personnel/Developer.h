#pragma once

#include "Employee.h"
#include <iostream>

class Developer : public Employee {
public:
    Developer(std::string name, int id, std::string language);
    Employee* Clone() const override;
    void Display() const override;

private:
    std::string programming_language_;
};
