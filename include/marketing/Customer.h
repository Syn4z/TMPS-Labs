#pragma once

#include <string>

class Customer {
private:
    Customer(std::string name, int age);

public:
    Customer(const Customer&) = delete;
    Customer& operator=(const Customer&) = delete;

    static Customer& GetInstance(const std::string& name, int age);
    std::string GetName() const;
    int GetAge() const;

private:
    static Customer instance_;
    std::string name_;
    int age_;
};
