#include "../include/carManufacturing/CarImpl.h"
#include <iostream>


class ComercialCar : public CarImpl {
public:
    ComercialCar(const std::string& brand, const std::string& model, int year, const std::string features, double price, int quantity, const std::string& serialNr, const std::string& type) : 
        CarImpl(brand, model, year, features, price, quantity, serialNr), type(type) {}
    void setType(const std::string& newType) { type = newType; }
    std::string getType() const { return type; }

private:
    std::string type;
};    