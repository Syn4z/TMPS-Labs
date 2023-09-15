#pragma once

#include <string>
#include <vector>


struct AdDetails {
    std::string title;
    std::string content;
    double cost;
    double revenue;
};

class Advertisements {
public:
    Advertisements();
    void addAdvertisement(const AdDetails& ad);
    void displayAd(size_t index) const; 
    void displayAllAds() const;
    double getTotalProfit() const;
    size_t getAdCount() const;
    std::string getAdTitle(size_t index) const;
    void deleteAdvertisement(size_t index);

private:
    std::vector<AdDetails> ads;
};
