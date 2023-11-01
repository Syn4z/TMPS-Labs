#pragma once

#include <string>
#include "CarInterface.h"

class CarImpl : public CarInterface {
public:
    CarImpl(std::string  brand, std::string  model, int year, std::string  features, double price, int quantity, std::string  serialNr);
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
