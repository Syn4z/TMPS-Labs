#pragma once

#include <iostream>
#include "FreeAdvertisementImpl.h"

class FreeAdvertisementDisplay {
public:
    FreeAdvertisementDisplay(const FreeAdvertisementImpl& ad);

    void displayAd() const;

private:
    const FreeAdvertisementImpl& ad;
};
