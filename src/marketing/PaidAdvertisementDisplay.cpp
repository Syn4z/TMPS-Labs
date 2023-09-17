#include <iostream>
#include "PaidAdvertisementImpl.cpp"


class PaidAdvertisementDisplay {
public:
    PaidAdvertisementDisplay(const PaidAdvertisementImpl& ad) : ad(ad) {}
    void displayAd() const {
        std::cout << "Title: " << ad.getTitle() << std::endl;
        std::cout << "Content: " << ad.getContent() << std::endl;
        std::cout << "Cost: $" << ad.getCost() << std::endl;
        std::cout << "Feedback: " << ad.getFeedback() << std::endl;
        if (ad.getSuccess()) {
            std::cout << "Success: Yes" << std::endl;
        }
        else {
            std::cout << "Success: No" << std::endl;
        }
        std::cout << "---------------------------" << std::endl;
}

private:
    const PaidAdvertisementImpl& ad;
};
