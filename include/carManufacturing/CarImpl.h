#pragma once

#include <string>
#include "Car.h"

class CarImpl : public Car {
public:
    CarImpl(const std::string& brand, const std::string& model, int year, const std::string& features, double price, int quantity, const std::string& serialNr);
    static CarImpl& getInstance();
    std::string getBrand() const override;
    std::string getModel() const override;
    int getYear() const override;
    std::string getFeatures() const override;
    double getPrice() const override;
    int getQuantity() const override;
    std::string getSerialNr() const override;
    std::string getType() const override;
    void setQuantity(int newQuantity) override;
    void setType() override;
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
