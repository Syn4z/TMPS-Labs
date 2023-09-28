#pragma once

#include <string>
#include "Advertisement.h"
#include "Customer.h"


class PaidAdvertisement : public Advertisement {
public:
    virtual double getCost() const = 0;
    virtual int getFeedback() const = 0;
    virtual bool getSuccess() const = 0;
    virtual bool receiveAdvertisement(const Customer* customer) const = 0;
};
