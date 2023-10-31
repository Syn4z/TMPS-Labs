#pragma once

#include "CarActions.h"

class SedanActions : public CarActions {
public:
    void drive() override;
    void stop() override;
};
