#pragma once

#include "CarActions.h"

class CivilCar {
protected:
    CarActions* actions;

public:
    explicit CivilCar(CarActions* carActions);
    virtual void driveCar();
    virtual void stopCar();
    virtual void accelerate();
};
