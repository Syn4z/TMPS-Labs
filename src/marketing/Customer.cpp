#include "../include/marketing/Customer.h"
#include <iostream>

std::vector<Customer*> Customer::instances_;
std::mutex Customer::mutex_;

Customer::Customer(const std::string& name, int age) : name_(name), age_(age) {}

Customer* Customer::GetInstance(const std::string& name, int age)
{
    std::lock_guard<std::mutex> lock(mutex_);
    for (Customer* customer : instances_) {
        if (customer->GetName() == name && customer->GetAge() == age) {
            return customer; // Return existing instance if found
        }
    }

    // If not found, create a new instance
    Customer* newCustomer = new Customer(name, age);
    instances_.push_back(newCustomer);
    return newCustomer;
}

std::string Customer::GetName() const
{
    return name_;
}

int Customer::GetAge() const
{
    return age_;
}

std::vector<Customer*> Customer::GetAllCustomers()
{
    return instances_;
}
