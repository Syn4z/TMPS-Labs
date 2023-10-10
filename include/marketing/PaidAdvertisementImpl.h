#pragma once

#include "PaidAdvertisement.h"
#include <iostream>

class PaidAdvertisementImpl : public PaidAdvertisement {
public:
    PaidAdvertisementImpl(std::string  title, std::string  content, double cost, int feedback);
    std::string getTitle() const override;
    std::string getContent() const override;
    double getCost() const override;
    int getFeedback() const override;
    bool getSuccess() const override;
    bool receiveAdvertisement(const Customer* customer, int age) const override;

private:
    std::string title;
    std::string content;
    double cost;
    int feedback;
};
