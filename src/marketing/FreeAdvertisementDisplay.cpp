#include <iostream>
#include "../../include/marketing/FreeAdvertisementDisplay.h"

FreeAdvertisementDisplay::FreeAdvertisementDisplay(const FreeAdvertisementImpl& ad) : ad(ad) {}

void FreeAdvertisementDisplay::displayAd() const {
    std::cout << "Title: " << ad.getTitle() << std::endl;
    std::cout << "Content: " << ad.getContent() << std::endl;
    std::cout << "Feedback: " << ad.getFeedback() << std::endl;
    std::cout << "---------------------------" << std::endl;
}
