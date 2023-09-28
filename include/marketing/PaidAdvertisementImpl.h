#pragma once

#include "PaidAdvertisement.h"
#include <iostream>

class PaidAdvertisementImpl : public PaidAdvertisement {
public:
    PaidAdvertisementImpl(const std::string& title, const std::string& content, double cost, int feedback);

    std::string getTitle() const;
    std::string getContent() const;
    double getCost() const;
    int getFeedback() const;
    bool getSuccess() const;
    bool receiveAdvertisement(const Customer* customer) const;

private:
    std::string title;
    std::string content;
    double cost;
    int feedback;
};