#pragma once
#include <string>

class CarInterface {
public:
    virtual ~CarInterface() {}

    virtual void setQuantity(int newQuantity) = 0;
    virtual double calculateProfit(double costPrice) const = 0;
    virtual void displayInfo() const = 0;
    virtual std::string getSerialNr() const = 0;
    virtual double getPrice() const = 0;
};    
