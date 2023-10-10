#include "../include/marketing/Customer.h"

Customer Customer::instance_("Default Name", 0);

Customer::Customer(std::string name, int age) : name_(std::move(name)), age_(age) {}

Customer& Customer::GetInstance(const std::string& name, int age) {
    if (instance_.GetName() != name || instance_.GetAge() != age) {
        instance_.name_ = name;
        instance_.age_ = age;
    }
    return instance_;
}

std::string Customer::GetName() const {
    return name_;
}

int Customer::GetAge() const {
    return age_;
}
