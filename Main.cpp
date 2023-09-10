#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "include/carManufacturing/CarModel.h"

using json = nlohmann::json;

// TO DO implement SOLID principles
// Interfaces, make the CarModel class abstract
// Implement an inherited class from CarModel
// Get a reason for Open-Closed Principle
// Get a reason for Liskov Substitution Principle
int main() {
    std::ifstream jsonFile("../data/carData.json");
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return 1;
    }

    json jsonData;
    jsonFile >> jsonData;
    jsonFile.close();

    for (const auto& carData : jsonData) {
        CarInfo carInfo;
        carInfo.brand = carData["brand"];
        carInfo.model = carData["model"];
        carInfo.year = carData["year"];
        carInfo.price = carData["price"];

        CarModel carModel(carInfo);
        carModel.setFeatures(carData["features"]);

        std::cout << "  Car Information:" << std::endl;
        carModel.displayInfo();

        double costPrice = carInfo.price * 0.8;
        double profit = carModel.calculateProfit(costPrice);
        std::cout << "\nProduction Price: $" << costPrice << std::endl;
        std::cout << "Profit: $" << profit << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}
