#include "vehicle/actions/OffroadCar.h"

OffroadCar::OffroadCar(CarActions* carActions) : CivilCar(carActions) {}

void OffroadCar::driveCar() {
    CivilCar::driveCar();
}

void OffroadCar::stopCar() {
    CivilCar::stopCar();
}

void OffroadCar::accelerate() {
    CivilCar::accelerate();
}

void OffroadCar::turnOn4x4() {
    std::cout << "Turning on 4x4." << std::endl;
}
