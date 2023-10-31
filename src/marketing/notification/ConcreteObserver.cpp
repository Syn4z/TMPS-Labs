#include "../include/marketing/notification/ConcreteObserver.h"
#include <iostream>

ConcreteObserver::ConcreteObserver() = default;

void ConcreteObserver::update(const Notification& ad) {
    std::cout << "Sent an advertisement: " << ad.getContent() << std::endl;
}