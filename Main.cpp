#include "MasterHeader.h"
#include "include/carManufacturing/components/EngineFacade.h"


int main() {
    CarActions* sedanActions = new SedanActions();
    CarActions* suvActions = new SUVActions();
    auto* civilCar = new CivilCar(sedanActions);
    CivilCar* offRoadSUV = new OffroadCar(suvActions);
    auto* offroadCar1 = dynamic_cast<OffroadCar*>(offRoadSUV);

    civilCar->driveCar();
    civilCar->accelerate();
    civilCar->stopCar();
    std::cout << std::endl;
    offRoadSUV->driveCar();
    offRoadSUV->accelerate();
    offroadCar1->turnOn4x4();
    offRoadSUV->stopCar();

    delete civilCar;
    delete offRoadSUV;
    std::cout << std::endl;

    EngineFacade carEngine;
    std::cout << "Starting the car:\n";
    std::cout << carEngine.StartCar();

    std::cout << "Stopping the car:\n";
    std::cout << carEngine.StopCar();

    // Cars
    std::vector<std::shared_ptr<CarInterface>> cars;
    std::vector<std::shared_ptr<CarImpl>> commercialCars;
    // Marketing
    std::vector<FreeAdvertisementImpl> freeAds;
    std::vector<PaidAdvertisementImpl> paidAds;
    // Production
    SportsCarBuilder sportsCar;
    OffroadCarBuilder offroadCar;
    ElectricCarBuilder electricCar;

    Menu menuFacade(cars, commercialCars, freeAds, paidAds);
    menuFacade.run();

    return 0;
}
