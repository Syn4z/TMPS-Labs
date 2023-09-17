#include <iostream>
#include "../include/carManufacturing/PersonalCar.h"

class CarCosts {
public:
    CarCosts(const PersonalCar& car) : car(car) {
        productionCost = car.getPrice() * 0.5;
        marketingCost = car.getPrice() * 0.1;
        dealerCost = car.getPrice() * 0.1;
        tax = car.getPrice() * 0.2;
    }

    void display() const {
        std::cout << "\nCar Costs:" << std::endl;
        std::cout << "Production Cost: $" << productionCost << std::endl;
        std::cout << "Marketing Cost: $" << marketingCost << std::endl;
        std::cout << "Dealer Cost: $" << dealerCost << std::endl;
        std::cout << "Tax: $" << tax << std::endl;
    }

    double getAllCosts() const {
        return productionCost + marketingCost + dealerCost + tax;
    }

    double calculateProfit() const {
        return car.getPrice() - productionCost - marketingCost - dealerCost - tax;
    }

private:
    double productionCost;
    double marketingCost;
    double dealerCost;
    double tax;
    const PersonalCar& car;
};
