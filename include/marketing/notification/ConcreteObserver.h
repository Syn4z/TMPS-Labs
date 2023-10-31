#pragma once
#include "Observer.h"

class ConcreteObserver : public Observer {
public:
    ConcreteObserver();
    void update(const Notification& ad) override;
};