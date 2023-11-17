#pragma once

#include <memory>
#include "CarDecorator.h"

class TunedCarDecorator : public CarDecorator {
public:
    explicit TunedCarDecorator(std::shared_ptr<CarInterface> car);
    std::string getType() const override;
    std::string getFeatures() const override;
};
