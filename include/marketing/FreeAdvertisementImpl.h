#pragma once

#include "FreeAdvertisement.h"
#include <iostream>

class FreeAdvertisementImpl : public FreeAdvertisement {
public:
    FreeAdvertisementImpl(std::string  title, std::string  content, int feedback);
    std::string getTitle() const override;
    std::string getContent() const override;
    int getFeedback() const override;
    bool receiveAdvertisement(const Customer* customer) const override;

private:
    std::string title;
    std::string content;
    int feedback;
};
