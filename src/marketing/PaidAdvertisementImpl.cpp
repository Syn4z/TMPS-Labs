#include "../include/marketing/PaidAdvertisement.h"
#include <iostream>


class PaidAdvertisementImpl : public PaidAdvertisement {
public:
    PaidAdvertisementImpl(const std::string& title, const std::string& content, double cost, int feedback) :
        title(title), content(content), cost(cost), feedback(feedback) {}
    std::string getTitle() const { return title; }
    std::string getContent() const{ return content; }
    double getCost() const { return cost; }
    int getFeedback() const { return feedback; }
    bool getSuccess() const { 
        if (feedback > cost * 0.3) {
            return true;
        }
        else {
            return false;
        } 
    }

private:
    std::string title;
    std::string content;
    double cost;
    int feedback;
};
