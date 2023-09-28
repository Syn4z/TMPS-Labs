#pragma once

#include "CarImpl.h"
#include <iostream>

class CarInfoDisplay {
public:
    CarInfoDisplay(const CarImpl& car) : car(car) {}
    void display() const {
        std::cout << "Car Information:" << std::endl;
        std::cout << "Brand: " << car.getBrand() << std::endl;
        std::cout << "Model: " << car.getModel() << std::endl;
        std::cout << "Year: " << car.getYear() << std::endl;
        std::cout << "Price: $" << car.getPrice() << std::endl;
        std::cout << "Features: " << car.getFeatures() << std::endl;
        std::cout << "Quantity: " << car.getQuantity() << std::endl;
        std::cout << "Serial Number: " << car.getSerialNr() << std::endl;
        std::cout << "Type: " << car.getType() << std::endl;
    }

private:
    const CarImpl& car;
};
