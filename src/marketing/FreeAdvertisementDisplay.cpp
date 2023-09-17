#include <iostream>
#include "FreeAdvertisementImpl.cpp"


class FreeAdvertisementDisplay {
public:
    FreeAdvertisementDisplay(const FreeAdvertisementImpl& ad) : ad(ad) {}
    void displayAd() const {
        std::cout << "Title: " << ad.getTitle() << std::endl;
        std::cout << "Content: " << ad.getContent() << std::endl;
        std::cout << "Feedback: " << ad.getFeedback() << std::endl;
        std::cout << "---------------------------" << std::endl;
}

private:
    const FreeAdvertisementImpl& ad;
};
