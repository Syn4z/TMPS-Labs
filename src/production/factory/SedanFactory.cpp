#include "../include/production/factory/SedanFactory.h"
#include "../include/production//factory/Sedan.h"

CarInterface* SedanFactory::CreateCar(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) const {
    return new Sedan(brand, model, year, features, price, quantity, serialNr);
}
