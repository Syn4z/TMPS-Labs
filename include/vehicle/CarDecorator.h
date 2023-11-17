#pragma once

#include <memory>
#include "CarInterface.h"

class CarDecorator : public CarInterface {
protected:
    std::shared_ptr<CarInterface> car_;

public:
    explicit CarDecorator(std::shared_ptr<CarInterface> car);
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
};
