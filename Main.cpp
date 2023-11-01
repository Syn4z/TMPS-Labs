#include "MasterHeader.h"

int main() {
    // Cars
    std::vector<std::shared_ptr<CarInterface>> cars;

    // Marketing
    std::vector<FreeAdvertisementImpl> freeAds;
    std::vector<PaidAdvertisementImpl> paidAds;

    // Production
    SportsCarBuilder sportsCar;
    OffroadCarBuilder offroadCar;
    ElectricCarBuilder electricCar;

    // Main Menu
    Menu mainMenu(cars, freeAds, paidAds);
    mainMenu.run();

    return 0;
}
