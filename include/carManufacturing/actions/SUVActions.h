#pragma once

#include "carManufacturing/actions/CarActions.h"

class SUVActions : public CarActions {
public:
    void drive() override;
    void stop() override;
};
