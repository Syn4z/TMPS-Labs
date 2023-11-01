#include "production/builder/OffroadCarBuilder.h"

OffroadCarBuilder::OffroadCarBuilder() {
    product = new Product();
}

OffroadCarBuilder::~OffroadCarBuilder() {
    delete product;
}

void OffroadCarBuilder::buildEngine() {
    product->parts_.emplace_back("3.5L V6");
}

void OffroadCarBuilder::buildTransmission() {
    product->parts_.emplace_back("6-speed automatic (4WD)");
}

void OffroadCarBuilder::buildCarSuspension() {
    product->parts_.emplace_back("Springs and Shocks");
}

void OffroadCarBuilder::buildSteering() {
    product->parts_.emplace_back("Power Steering");
}

void OffroadCarBuilder::buildBody() {
    product->parts_.emplace_back("Pickup Truck");
}

Product* OffroadCarBuilder::GetProduct() {
    return product;
}
