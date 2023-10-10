#pragma once

#include <iostream>
#include "PaidAdvertisementImpl.h"

class PaidAdvertisementDisplay {
public:
    explicit PaidAdvertisementDisplay(const PaidAdvertisementImpl& ad);
    void displayAd() const;

private:
    const PaidAdvertisementImpl& ad;
};
