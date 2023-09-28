#include "../../include/marketing/FreeAdvertisementImpl.h"

FreeAdvertisementImpl::FreeAdvertisementImpl(const std::string& title, const std::string& content, int feedback)
        : title(title), content(content), feedback(feedback) {}

std::string FreeAdvertisementImpl::getTitle() const {
    return title;
}

std::string FreeAdvertisementImpl::getContent() const {
    return content;
}

int FreeAdvertisementImpl::getFeedback() const {
    return feedback;
}

bool FreeAdvertisementImpl::receiveAdvertisement(const Customer* customer) const {
    return customer->GetAge() > 18;
}
