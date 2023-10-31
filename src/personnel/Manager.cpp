#include <utility>

#include "../include/personnel/Manager.h"

Manager::Manager(std::string name, int id, int team_size)
        : Employee(std::move(name), id, MANAGER), team_size_(team_size) {}

Employee* Manager::Clone() const {
    return new Manager(*this);
}

void Manager::Display() const {
    Employee::Display();
    std::cout << "Team Size: " << team_size_ << "\n";
}
