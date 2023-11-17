#pragma once
#include "Notification.h"

class Observer {
public:
    virtual void update(const Notification& ad) = 0;
};
