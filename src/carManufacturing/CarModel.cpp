#include "../include/carManufacturing/CarModel.h"
#include <iostream>


CarModel::CarModel(const CarInfo& carInfo) 
    : carInfo(carInfo), features("") {
}

void CarModel::setFeatures(std::string newFeatures) {
    features = newFeatures;
}

double CarModel::calculateProfit(double costPrice) const {
    return carInfo.price - costPrice;
}

void CarModel::displayInfo() const {
    std::cout << "Car Brand: " << carInfo.brand << std::endl;
    std::cout << "Car Model: " << carInfo.model << std::endl;
    std::cout << "Year: " << carInfo.year << std::endl;
    std::cout << "Price: $" << carInfo.price << std::endl;
    std::cout << "Features: " << features << std::endl;
}
