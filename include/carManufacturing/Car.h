#pragma once

#include <string>


class Car {
public:
    virtual ~Car() {}
    virtual std::string getBrand() const = 0;
    virtual std::string getModel() const = 0;
    virtual int getYear() const = 0;
    virtual std::string getFeatures() const = 0;
    virtual double getPrice() const = 0;
    virtual int getQuantity() const = 0;
    virtual std::string getSerialNr() const = 0;
    virtual void setQuantity(int newQuantity) = 0;
};    
