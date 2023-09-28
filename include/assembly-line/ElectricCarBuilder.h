#pragma once

#include "CarBuilder.h"

class ElectricCarBuilder : public CarBuilder {
public:
    ElectricCarBuilder();
    ~ElectricCarBuilder() override;
    void buildEngine() override;
    void buildTransmission() override;
    void buildCarSuspension() override;
    void buildSteering() override;
    void buildBody() override;
    Product* GetProduct() override;

private:
    Product* product;
};
