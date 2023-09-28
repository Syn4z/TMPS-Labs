#include "../include/carManufacturing/CarImpl.h"
#include <string>

class ComercialCar : public CarImpl {
public:
    ComercialCar(
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
            type = "Comercial";
        }
    }
};
