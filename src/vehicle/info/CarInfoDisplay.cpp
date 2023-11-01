#include "vehicle/info/CarInfoDisplay.h"

CarInfoDisplay::CarInfoDisplay(const CarInfoStrategy& strategy) : strategy(strategy) {}

void CarInfoDisplay::displayCarInfo(const CarInterface& car) const {
    strategy.display(car);
}
