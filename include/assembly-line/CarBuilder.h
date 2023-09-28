#pragma once

#include "Product.h"

class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void buildEngine() = 0;
    virtual void buildTransmission() = 0;
    virtual void buildCarSuspension() = 0;
    virtual void buildSteering() = 0;
    virtual void buildBody() = 0;
    virtual Product* GetProduct() = 0;
};
