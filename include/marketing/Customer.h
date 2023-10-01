#pragma once

#include <string>
#include <vector>
#include <mutex>

class Customer {
private:
    static std::vector<Customer*> instances_;
    static std::mutex mutex_;

protected:
    Customer(std::string  name, int age);

public:
    Customer(Customer& other) = delete;
    void operator=(const Customer&) = delete;
    static Customer* GetInstance(const std::string& name, int age);
    std::string GetName() const;
    int GetAge() const;
    static std::vector<Customer*> GetAllCustomers();

private:
    std::string name_;
    int age_;
};
