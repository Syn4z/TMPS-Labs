#pragma once

#include "CarBuilder.h"

class SportsCarBuilder : public CarBuilder {
public:
    SportsCarBuilder();
    ~SportsCarBuilder() override;
    void buildEngine() override;
    void buildTransmission() override;
    void buildCarSuspension() override;
    void buildSteering() override;
    void buildBody() override;
    Product* GetProduct() override;

private:
    Product* product;
};
