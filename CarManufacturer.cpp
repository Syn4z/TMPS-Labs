#include <iostream>
#include "include/CarModel.h"

int main() {
    // Create instances of CarModel
    CarModel model1("Sedan", 2023, 30000.0);
    CarModel model2("SUV", 2023, 35000.0);
    
    // Set or update the features
    model1.setFeatures("Advanced safety features, GPS, leather seats");
    model2.setFeatures("Off-road capability, spacious interior");

    // Display information about the car models
    std::cout << "Car Model 1 Information:" << std::endl;
    model1.displayInfo();
    
    std::cout << "\nCar Model 2 Information:" << std::endl;
    model2.displayInfo();

    // Calculate profit (assuming a cost price of $25000)
    double costPrice = 25000.0;
    double profit1 = model1.calculateProfit(costPrice);
    double profit2 = model2.calculateProfit(costPrice);

    std::cout << "\nProfit for Car Model 1: $" << profit1 << std::endl;
    std::cout << "Profit for Car Model 2: $" << profit2 << std::endl;

    return 0;
}
