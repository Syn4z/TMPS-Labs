#include "../include/marketing/FreeAdvertisement.h"
#include <iostream>


class FreeAdvertisementImpl : public FreeAdvertisement {
public:
    FreeAdvertisementImpl(const std::string& title, const std::string& content, int feedback) :
            title(title), content(content), feedback(feedback) {}

    std::string getTitle() const { return title; }
    std::string getContent() const { return content; }
    int getFeedback() const { return feedback; }
    bool receiveAdvertisement(const Customer* customer) const {
        return customer->GetAge() > 18;
    }

private:
    std::string title;
    std::string content;
    int feedback;
};
