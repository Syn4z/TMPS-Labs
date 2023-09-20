#include "../include/carManufacturing/CarImpl.h"
#include <iostream>


CarImpl::CarImpl(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr) : 
    brand(brand), model(model), year(year), features(features), price(price), quantity(quantity), serialNr(serialNr) {}
std::string CarImpl::getBrand() const { return brand; }
std::string CarImpl::getModel() const { return model; }
int CarImpl::getYear() const { return year; }
std::string CarImpl::getFeatures() const { return features; }
double CarImpl::getPrice() const { return price; }
int CarImpl::getQuantity() const { return quantity; }
std::string CarImpl::getSerialNr() const { return serialNr; }
void CarImpl::setQuantity(int newQuantity) { quantity = newQuantity; }
