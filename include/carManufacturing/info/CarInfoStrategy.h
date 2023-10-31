#pragma once

#include "../CarInterface.h"

class CarInfoStrategy {
public:
    virtual void display(const CarInterface& car) const = 0;
    virtual ~CarInfoStrategy() = default;
};