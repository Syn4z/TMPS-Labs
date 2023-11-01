#include <utility>
#include "../../include/vehicle/TunedCarDecorator.h"

TunedCarDecorator::TunedCarDecorator(std::shared_ptr<CarInterface> car) : CarDecorator(std::move(car)) {}

std::string TunedCarDecorator::getType() const {
    return "Personal Tuned";
}

std::string TunedCarDecorator::getFeatures() const {
    return car_->getFeatures() + ", Tuned";
}
