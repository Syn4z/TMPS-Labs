#pragma once

#include "CarImpl.h"
#include <iostream>

class CarCosts {
public:
    CarCosts(const CarImpl& car);

    void display() const;
    double getAllCosts() const;
    double calculateProfit() const;

private:
    double productionCost;
    double marketingCost;
    double dealerCost;
    double tax;
    const CarImpl& car;
};
