#pragma once

#include "CarBuilder.h"

class OffroadCarBuilder : public CarBuilder {
public:
    OffroadCarBuilder();
    ~OffroadCarBuilder();
    void buildEngine() override;
    void buildTransmission() override;
    void buildCarSuspension() override;
    void buildSteering() override;
    void buildBody() override;
    Product* GetProduct() override;

private:
    Product* product;
};
