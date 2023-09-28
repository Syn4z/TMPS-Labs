#pragma once

#include <iostream>
#include "PaidAdvertisementImpl.h"

class PaidAdvertisementDisplay {
public:
    PaidAdvertisementDisplay(const PaidAdvertisementImpl& ad);

    void displayAd() const;

private:
    const PaidAdvertisementImpl& ad;
};
