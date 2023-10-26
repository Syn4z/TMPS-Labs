#include "FuelSystem.h"
#include "CoolingSystem.h"
#include "IgnitionSystem.h"

class EngineFacade {
private:
    FuelSystem* fuelSystem;
    CoolingSystem* coolingSystem;
    IgnitionSystem* ignitionSystem;

public:
    EngineFacade();
    ~EngineFacade();
    std::string StartCar();
    std::string StopCar();
};
