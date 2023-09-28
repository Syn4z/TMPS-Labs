#pragma once

#include <string>
#include "Advertisement.h"
#include "Customer.h"


class FreeAdvertisement : public Advertisement {
public:
    virtual int getFeedback() const = 0;
    virtual bool receiveAdvertisement(const Customer* customer) const = 0;
};
