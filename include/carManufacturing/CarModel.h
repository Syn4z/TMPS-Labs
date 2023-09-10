#pragma once

#include <string>


struct CarInfo {
    std::string brand;
    std::string model;
    int year;
    double price;
};

class CarModel {
public:
    CarModel(const CarInfo& carInfo);

    void setFeatures(std::string newFeatures);

    double calculateProfit(double costPrice) const;

    void displayInfo() const;

private:
    CarInfo carInfo;
    std::string features;
};
