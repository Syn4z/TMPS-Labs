#include "carManufacturing/actions/CivilCar.h"
#include <iostream>

CivilCar::CivilCar(CarActions* carActions) : actions(carActions) {}

void CivilCar::driveCar() {
    actions->drive();
}

void CivilCar::stopCar() {
    actions->stop();
}

void CivilCar::accelerate() {
    std::cout << "Accelerating the car." << std::endl;
}
