#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "../../MasterHeader.h"

class Menu {
public:
    explicit Menu(std::vector<std::shared_ptr<CarInterface>> &cars, std::vector<std::shared_ptr<CarImpl>> &commercialCars, std::vector<FreeAdvertisementImpl> &freeAds, std::vector<PaidAdvertisementImpl> &paidAds);
    void run();

private:
    static int showMainMenu();
    void handleCarInformation();
    void handleMarketingInformation();
    static void handleProductionInformation();
    static void handleStaffInformation();
    static bool isValidDoubleInput(const std::string& input);
    static void ClientCode(const CarFactory& factory, std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr);
    std::vector<std::shared_ptr<CarInterface>>& cars;
    std::vector<std::shared_ptr<CarImpl>> &commercialCars;
    std::vector<FreeAdvertisementImpl> &freeAds;
    std::vector<PaidAdvertisementImpl> &paidAds;
};
