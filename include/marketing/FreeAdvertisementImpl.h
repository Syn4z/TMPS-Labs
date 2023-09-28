#pragma once

#include "FreeAdvertisement.h"
#include <iostream>

class FreeAdvertisementImpl : public FreeAdvertisement {
public:
    FreeAdvertisementImpl(const std::string& title, const std::string& content, int feedback);

    std::string getTitle() const;
    std::string getContent() const;
    int getFeedback() const;
    bool receiveAdvertisement(const Customer* customer) const;

private:
    std::string title;
    std::string content;
    int feedback;
};
