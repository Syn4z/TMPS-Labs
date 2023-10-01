#pragma once

#include "CarFactory.h"

class SedanFactory : public CarFactory {
public:
    CarInterface* CreateCar(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) const override;
};
