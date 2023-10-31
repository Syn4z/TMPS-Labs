#include "../include/personnel/EmployeeFactory.h"
#include "../include/personnel/Manager.h"
#include "../include/personnel/Developer.h"

EmployeeFactory::EmployeeFactory() {
    prototypes_[MANAGER] = new Manager("John Jonson", 1, 5);
    prototypes_[DEVELOPER] = new Developer("Uncle Bob", 2, "C++");
}

EmployeeFactory::~EmployeeFactory() {
    delete prototypes_[MANAGER];
    delete prototypes_[DEVELOPER];
}

Employee* EmployeeFactory::CreateEmployee(EmployeeType type) {
    return prototypes_[type]->Clone();
}
