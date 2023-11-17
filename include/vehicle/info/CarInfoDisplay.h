#pragma once

#include "../CarInterface.h"
#include "CarInfoStrategy.h"

class CarInfoDisplay {
public:
    explicit CarInfoDisplay(const CarInfoStrategy& strategy);
    void displayCarInfo(const CarInterface& car) const;

private:
    const CarInfoStrategy& strategy;
};
