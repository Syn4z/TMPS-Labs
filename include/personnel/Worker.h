#pragma once

#include "Employee.h"
#include <string>
#include <iostream>

class Worker : public Employee {
private:
    std::string name;

public:
    explicit Worker(std::string  name);
    void work() const override;
};

