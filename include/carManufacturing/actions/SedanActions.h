#pragma once

#include "carManufacturing/actions/CarActions.h"

class SedanActions : public CarActions {
public:
    void drive() override;
    void stop() override;
};
