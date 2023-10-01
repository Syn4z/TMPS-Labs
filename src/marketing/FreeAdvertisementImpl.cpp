#include <utility>
#include "../../include/marketing/FreeAdvertisementImpl.h"

FreeAdvertisementImpl::FreeAdvertisementImpl(std::string  title, std::string  content, int feedback)
        : title(std::move(title)), content(std::move(content)), feedback(feedback) {}

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
