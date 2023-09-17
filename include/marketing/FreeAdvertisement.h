#pragma once

#include <string>
#include "Advertisement.h"


class FreeAdvertisement : public Advertisement {
public:
    virtual int getFeedback() const = 0;
};
