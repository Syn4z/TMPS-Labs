#include "../include/carManufacturing/factory/SUVFactory.h"
#include "../include/carManufacturing/factory/SUV.h"

CarInterface* SUVFactory::CreateCar(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) const {
    return new SUV(brand, model, year, features, price, quantity, serialNr);
}
