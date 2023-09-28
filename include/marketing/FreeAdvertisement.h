#pragma once

#include <string>
#include "Advertisement.h"
#include "Customer.h"


class FreeAdvertisement : public Advertisement {
public:
    int getFeedback() const override = 0;
    virtual bool receiveAdvertisement(const Customer* customer) const = 0;
};
