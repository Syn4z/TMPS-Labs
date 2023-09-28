#include "../../include/assembly-line/OffroadCarBuilder.h"
#include "../../include/assembly-line/Product.h"

OffroadCarBuilder::OffroadCarBuilder() {
    product = new Product();
}

OffroadCarBuilder::~OffroadCarBuilder() {
    delete product;
}

void OffroadCarBuilder::buildEngine() {
    product->parts_.push_back("3.5L V6");
}

void OffroadCarBuilder::buildTransmission() {
    product->parts_.push_back("6-speed automatic (4WD)");
}

void OffroadCarBuilder::buildCarSuspension() {
    product->parts_.push_back("Springs and Shocks");
}

void OffroadCarBuilder::buildSteering() {
    product->parts_.push_back("Power Steering");
}

void OffroadCarBuilder::buildBody() {
    product->parts_.push_back("Pickup Truck");
}

Product* OffroadCarBuilder::GetProduct() {
    return product;
}
