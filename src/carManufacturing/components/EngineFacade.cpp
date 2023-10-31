#include "../../../include/carManufacturing/components/EngineFacade.h"

EngineFacade::EngineFacade() {
    fuelSystem = new FuelSystem();
    coolingSystem = new CoolingSystem();
    ignitionSystem = new IgnitionSystem();
}

EngineFacade::~EngineFacade() {
    delete fuelSystem;
    delete coolingSystem;
    delete ignitionSystem;
}

std::string EngineFacade::StartCar() {
    std::string result = "EngineFacade: Starting the car components.\n";
    result += ignitionSystem->StartIgnition(); // NOLINT(*-static-accessed-through-instance)
    result += fuelSystem->SupplyFuel(); // NOLINT(*-static-accessed-through-instance)
    result += coolingSystem->CoolEngine(); // NOLINT(*-static-accessed-through-instance)
    return result;
}

std::string EngineFacade::StopCar() {
    std::string result = "EngineFacade: Stopping the car components.\n";
    result += ignitionSystem->StopIgnition(); // NOLINT(*-static-accessed-through-instance)
    result += coolingSystem->StopCooling(); // NOLINT(*-static-accessed-through-instance)
    result += fuelSystem->StopFuelSupply(); // NOLINT(*-static-accessed-through-instance)
    return result;
}
