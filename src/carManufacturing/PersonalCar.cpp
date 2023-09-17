#include "../include/carManufacturing/PersonalCar.h"
#include <iostream>


PersonalCar::PersonalCar(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr)
    : brand(brand), model(model), year(year), features(features), price(price), quantity(quantity), serialNr(serialNr) {
}

std::string PersonalCar::getBrand() const {
    return brand;
}

std::string PersonalCar::getModel() const {
    return model;
}

int PersonalCar::getYear() const {
    return year;
}

std::string PersonalCar::getFeatures() const {
    return features;
}

double PersonalCar::getPrice() const {
    return price;
}

int PersonalCar::getQuantity() const {
    return quantity;
}

std::string PersonalCar::getSerialNr() const {
    return serialNr;
}

void PersonalCar::setQuantity(int newQuantity) {
    quantity = newQuantity;
}
