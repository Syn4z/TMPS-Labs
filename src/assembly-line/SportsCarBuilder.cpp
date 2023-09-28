#include "../../include/assembly-line/SportsCarBuilder.h"
#include "../../include/assembly-line/Product.h"

SportsCarBuilder::SportsCarBuilder() {
    product = new Product();
}

SportsCarBuilder::~SportsCarBuilder() {
    delete product;
}

void SportsCarBuilder::buildEngine() {
    product->parts_.push_back("Engine: 4.0L Flat-Six");
}

void SportsCarBuilder::buildTransmission() {
    product->parts_.push_back("8-speed dual clutch automatic");
}

void SportsCarBuilder::buildCarSuspension() {
    product->parts_.push_back("Air suspension");
}

void SportsCarBuilder::buildSteering() {
    product->parts_.push_back("Power Rack and Pinion");
}

void SportsCarBuilder::buildBody() {
    product->parts_.push_back("Coupe");
}

Product* SportsCarBuilder::GetProduct() {
    return product;
}