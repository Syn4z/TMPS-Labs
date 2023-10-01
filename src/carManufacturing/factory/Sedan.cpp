#include <utility>
#include "../../../include/carManufacturing/factory/Sedan.h"

Sedan::Sedan(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr)
        : brand_(std::move(brand)), model_(std::move(model)), year_(year), features_(std::move(features)), price_(price), quantity_(quantity), serialNr_(std::move(serialNr)) {}

std::string Sedan::getBrand() const {
    return brand_;
}

std::string Sedan::getModel() const {
    return model_;
}

int Sedan::getYear() const {
    return year_;
}

std::string Sedan::getFeatures() const {
    return features_;
}

double Sedan::getPrice() const {
    return price_;
}

int Sedan::getQuantity() const {
    return quantity_;
}

std::string Sedan::getSerialNr() const {
    return serialNr_;
}

std::string Sedan::getType() const {
    return type_;
}

void Sedan::setQuantity(int newQuantity) {
    quantity_ = newQuantity;
}

void Sedan::setType() {
    type_ = "Sedan";
}
