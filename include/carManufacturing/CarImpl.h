#pragma once

#include <string>
#include "Car.h"

class CarImpl : public Car {
public:
    CarImpl(const std::string& brand, const std::string& model, int year, const std::string& features, double price, int quantity, const std::string& serialNr);
    static CarImpl& getInstance();
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    std::string getFeatures() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getSerialNr() const;
    std::string getType() const;
    void setQuantity(int newQuantity);
    virtual void setType();
    std::string type;    

private:
    std::string brand;
    std::string model;
    int year;
    double price;
    std::string features;
    int quantity;
    std::string serialNr;
};
