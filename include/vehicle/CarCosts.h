#pragma once

#include "CarInterface.h"
#include <iostream>

class CarCosts {
public:
    explicit CarCosts(const CarInterface& car);
    void display() const;
    double getAllCosts() const;
    double calculateProfit() const;

private:
    double productionCost;
    double marketingCost;
    double dealerCost;
    double tax;
    const CarInterface& car;
};
