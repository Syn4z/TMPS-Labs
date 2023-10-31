#pragma once

#include "CarInfoStrategy.h"
#include <iostream>

class SummaryCarInfo : public CarInfoStrategy {
public:
    void display(const CarInterface& car) const override;
};