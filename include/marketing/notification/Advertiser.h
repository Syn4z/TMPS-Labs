#pragma once
#include <vector>
#include "Observer.h"

class Advertiser {
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }
    void notifyObservers(const Notification& ad) {
        for (Observer* observer : observers) {
            observer->update(ad);
        }
    }

private:
    std::vector<Observer*> observers;
};
