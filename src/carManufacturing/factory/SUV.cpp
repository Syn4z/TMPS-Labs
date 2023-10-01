#include <utility>

#include "../../../include/carManufacturing/factory/SUV.h"

SUV::SUV(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr)
        : brand_(std::move(brand)), model_(std::move(model)), year_(year), features_(std::move(features)), price_(price), quantity_(quantity), serialNr_(std::move(serialNr)) {}

std::string SUV::getBrand() const {
    return brand_;
}

std::string SUV::getModel() const {
    return model_;
}

int SUV::getYear() const {
    return year_;
}

std::string SUV::getFeatures() const {
    return features_;
}

double SUV::getPrice() const {
    return price_;
}

int SUV::getQuantity() const {
    return quantity_;
}

std::string SUV::getSerialNr() const {
    return serialNr_;
}

std::string SUV::getType() const {
    return type_;
}

void SUV::setQuantity(int newQuantity) {
    quantity_ = newQuantity;
}

void SUV::setType() {
    type_ = "SUV";
}
