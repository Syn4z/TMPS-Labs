#include "../../include/personnel/Supervisor.h"
#include <iostream>
#include <utility>

Supervisor::Supervisor(std::string  name) : name(std::move(name)) { }

void Supervisor::work() const {
    std::cout << "Supervisor " << name << " is supervising the team." << std::endl;
    for (const auto& employee : employees) {
        employee->work();
    }
}

void Supervisor::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

Supervisor::~Supervisor() {
    for (auto employee : employees) {
        delete employee;
    }
}
