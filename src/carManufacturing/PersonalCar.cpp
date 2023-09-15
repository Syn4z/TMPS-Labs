#include "../include/carManufacturing/PersonalCar.h"
#include <iostream>


PersonalCar::PersonalCar(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr)
    : brand(brand), model(model), year(year), price(price), quantity(quantity), serialNr(serialNr) {
}

void PersonalCar::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

double PersonalCar::calculateProfit(double costPrice) const {
    return price - costPrice;
}

std::string PersonalCar::getSerialNr() const {
    return serialNr;
}

double PersonalCar::getPrice() const {
    return price;
}

void PersonalCar::displayInfo() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Features: " << features << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Serial Number: " << serialNr << std::endl;
}
