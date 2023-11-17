#pragma once

#include "../../vehicle/CarInterface.h"

class CarFactory {
public:
    virtual ~CarFactory() = default;
    virtual CarInterface* CreateCar(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) const = 0;
};
