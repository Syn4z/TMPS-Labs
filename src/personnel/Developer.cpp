#include <utility>

#include "../include/personnel/Developer.h"

Developer::Developer(std::string name, int id, std::string language)
        : Employee(std::move(name), id, DEVELOPER), programming_language_(std::move(language)) {}

Employee* Developer::Clone() const {
    return new Developer(*this);
}

void Developer::Display() const {
    Employee::Display();
    std::cout << "Programming Language: " << programming_language_ << "\n";
}
