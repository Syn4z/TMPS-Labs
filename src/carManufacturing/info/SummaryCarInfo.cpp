#include "carManufacturing/info/SummaryCarInfo.h"

void SummaryCarInfo::display(const CarInterface& car) const {
    std::cout << "Car Information:" << std::endl;
    std::cout << "Brand: " << car.getBrand() << std::endl;
    std::cout << "Model: " << car.getModel() << std::endl;
    std::cout << "Year: " << car.getYear() << std::endl;
    std::cout << "Price: $" << car.getPrice() << std::endl;
}