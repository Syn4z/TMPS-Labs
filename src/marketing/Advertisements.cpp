#include "../include/marketing/Advertisements.h"
#include <iostream>


Advertisements::Advertisements() {}

void Advertisements::addAdvertisement(const AdDetails& ad) {
    ads.push_back(ad);
}

void Advertisements::displayAd(size_t index) const { 
    if (index < ads.size()) {
        const AdDetails& ad = ads[index];
        std::cout << "Title: " << ad.title << std::endl;
        std::cout << "Content: " << ad.content << std::endl;
        std::cout << "Cost: $" << ad.cost << std::endl;
        std::cout << "Revenue: $" << ad.revenue << std::endl;
        std::cout << "Profit: $" << (ad.revenue - ad.cost) << std::endl;
        std::cout << "---------------------------" << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void Advertisements::displayAllAds() const {
    if (ads.empty()) {
        std::cout << "No ads to display." << std::endl;
        return;
    }
    for (size_t i = 0; i < ads.size(); ++i) {
        displayAd(i);
    }
}

double Advertisements::getTotalProfit() const {
    double totalProfit = 0.0;
    for (const auto& ad : ads) {
        totalProfit += (ad.revenue - ad.cost);
    }
    return totalProfit;
}

std::string Advertisements::getAdTitle(size_t index) const {
    if (index < ads.size()) {
        return ads[index].title;
    } else {
        return "";
    }
}

void Advertisements::deleteAdvertisement(size_t index) {
    if (index < ads.size()) {
        ads.erase(ads.begin() + index);
        std::cout << "Advertisement deleted successfully" << std::endl;
    }

    std::cout << "Advertisement not found" << std::endl;
}

size_t Advertisements::getAdCount() const {
    return ads.size();
}
