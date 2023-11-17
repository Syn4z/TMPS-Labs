#include "../include/marketing/notification/ConcreteObserver.h"
#include <iostream>

ConcreteObserver::ConcreteObserver() = default;

void ConcreteObserver::update(const Notification& ad) {
    std::cout << "Received an advertisement: " << ad.getContent() << std::endl;
}
