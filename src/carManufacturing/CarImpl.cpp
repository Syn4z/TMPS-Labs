#include "../include/carManufacturing/CarImpl.h"
#include <utility>

CarImpl::CarImpl(
    std::string  brand,
    std::string  model,
    int year, 
    std::string  features,
    double price, 
    int quantity, 
    std::string  serialNr
) : brand(std::move(brand)), model(std::move(model)), year(year), features(std::move(features)), price(price), quantity(quantity), serialNr(std::move(serialNr)), type(type) {}
std::string CarImpl::getBrand() const { return brand; }
std::string CarImpl::getModel() const { return model; }
int CarImpl::getYear() const { return year; }
std::string CarImpl::getFeatures() const { return features; }
double CarImpl::getPrice() const { return price; }
int CarImpl::getQuantity() const { return quantity; }
std::string CarImpl::getSerialNr() const { return serialNr; }
std::string CarImpl::getType() const { return type; }
void CarImpl::setQuantity(int newQuantity) { quantity = newQuantity; }
void CarImpl::setType() {
    if (serialNr.find("-P") != std::string::npos) {
        type = "Personal";
    }
}
