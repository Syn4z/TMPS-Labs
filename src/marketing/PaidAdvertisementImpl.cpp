#include <utility>

#include "../../include/marketing/PaidAdvertisementImpl.h"

PaidAdvertisementImpl::PaidAdvertisementImpl(std::string  title, std::string  content, double cost, int feedback)
        : title(std::move(title)), content(std::move(content)), cost(cost), feedback(feedback) {}

std::string PaidAdvertisementImpl::getTitle() const {
    return title;
}

std::string PaidAdvertisementImpl::getContent() const {
    return content;
}

double PaidAdvertisementImpl::getCost() const {
    return cost;
}

int PaidAdvertisementImpl::getFeedback() const {
    return feedback;
}

bool PaidAdvertisementImpl::getSuccess() const {
    return feedback > cost * 0.3;
}

bool PaidAdvertisementImpl::receiveAdvertisement(const Customer* customer, int age) const {
    return customer->GetAge() > age;
}
