#include "../../include/marketing/PaidAdvertisementImpl.h"

PaidAdvertisementImpl::PaidAdvertisementImpl(const std::string& title, const std::string& content, double cost, int feedback)
        : title(title), content(content), cost(cost), feedback(feedback) {}

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

bool PaidAdvertisementImpl::receiveAdvertisement(const Customer* customer) const {
    return customer->GetAge() > 18;
}
