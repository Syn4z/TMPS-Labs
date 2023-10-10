#pragma once

#include "../CarInterface.h"

class SUV : public CarInterface {
public:
    SUV(std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr);
    std::string getBrand() const override;
    std::string getModel() const override;
    int getYear() const override;
    std::string getFeatures() const override;
    double getPrice() const override;
    int getQuantity() const override;
    std::string getSerialNr() const override;
    std::string getType() const override;
    void setQuantity(int newQuantity) override;
    void setType() override;

private:
    std::string brand_;
    std::string model_;
    int year_;
    std::string features_;
    double price_;
    int quantity_;
    std::string serialNr_;
    std::string type_;
};
