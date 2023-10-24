#pragma once

#include "CivilCar.h"
#include <iostream>

class OffroadCar : public CivilCar {
public:
    explicit OffroadCar(CarActions* carActions);
    void driveCar() override;
    void stopCar() override;
    void accelerate() override;
    virtual void turnOn4x4();
};
