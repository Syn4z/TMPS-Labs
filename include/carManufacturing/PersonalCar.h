#pragma once

#include <string>
#include <iostream>
#include "CarInterface.h"


class PersonalCar : public CarInterface {
public:
    PersonalCar(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr);

    void setQuantity(int newQuantity) override;
    double calculateProfit(double costPrice) const override;
    void displayInfo() const override;
    std::string getSerialNr() const;
    double getPrice() const;

private:
    std::string brand;
    std::string model;
    int year;
    double price;
    std::string features;
    int quantity;
    std::string serialNr;
};
