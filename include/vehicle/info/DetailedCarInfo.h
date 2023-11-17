#pragma once

#include "CarInfoStrategy.h"
#include <iostream>

class DetailedCarInfo : public CarInfoStrategy {
public:
    void display(const CarInterface& car) const override;
};
