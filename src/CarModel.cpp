#include "../include/CarModel.h"
#include <iostream>

// Constructor implementation
CarModel::CarModel(std::string name, int year, double price) 
    : name(name), year(year), price(price) {
    // Initialize other attributes as needed
    features = "";
}

// Method to set or update the features of the car model
void CarModel::setFeatures(std::string newFeatures) {
    features = newFeatures;
}

// Method to calculate the profit for the car model
double CarModel::calculateProfit(double costPrice) const {
    return price - costPrice;
}

// Method to display information about the car model
void CarModel::displayInfo() const {
    std::cout << "Car Model: " << name << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Features: " << features << std::endl;
}
