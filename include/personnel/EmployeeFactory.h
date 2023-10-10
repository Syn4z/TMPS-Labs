#pragma once

#include "Employee.h"
#include <unordered_map>

class EmployeeFactory {
public:
    EmployeeFactory();
    ~EmployeeFactory();
    Employee* CreateEmployee(EmployeeType type);

private:
    std::unordered_map<EmployeeType, Employee*, std::hash<int>> prototypes_;
};
