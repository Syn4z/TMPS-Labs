#pragma once

#include "CarImpl.h"
#include <string>

class CommercialCar : public CarImpl {
public:
    CommercialCar(
            const std::string& brand,
            const std::string& model,
            int year,
            const std::string& features,
            double price,
            int quantity,
            const std::string& serialNr
    ) : CarImpl(brand, model, year, features, price, quantity, serialNr) {}

    void setType() override {
        if (getSerialNr().find("-CM") != std::string::npos) {
            type = "Commercial";
        }
    }
};
