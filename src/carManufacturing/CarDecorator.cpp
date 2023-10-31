#include "../../include/carManufacturing/CarDecorator.h"

CarDecorator::CarDecorator(std::shared_ptr<CarInterface> car) : car_(car) {}

std::string CarDecorator::getBrand() const {
    return car_->getBrand();
}

std::string CarDecorator::getModel() const {
    return car_->getModel();
}

int CarDecorator::getYear() const {
    return car_->getYear();
}

std::string CarDecorator::getFeatures() const {
    return car_->getFeatures();
}

double CarDecorator::getPrice() const {
    return car_->getPrice();
}

int CarDecorator::getQuantity() const {
    return car_->getQuantity();
}

std::string CarDecorator::getSerialNr() const {
    return car_->getSerialNr();
}

std::string CarDecorator::getType() const {
    return car_->getType();
}

void CarDecorator::setQuantity(int newQuantity) {
    car_->setQuantity(newQuantity);
}

void CarDecorator::setType() {
    car_->setType();
}
