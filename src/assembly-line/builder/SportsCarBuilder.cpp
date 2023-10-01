#include "assembly-line/builder/SportsCarBuilder.h"

SportsCarBuilder::SportsCarBuilder() {
    product = new Product();
}

SportsCarBuilder::~SportsCarBuilder() {
    delete product;
}

void SportsCarBuilder::buildEngine() {
    product->parts_.emplace_back("4.0L Flat-Six");
}

void SportsCarBuilder::buildTransmission() {
    product->parts_.emplace_back("8-speed dual clutch automatic");
}

void SportsCarBuilder::buildCarSuspension() {
    product->parts_.emplace_back("Air suspension");
}

void SportsCarBuilder::buildSteering() {
    product->parts_.emplace_back("Power Rack and Pinion");
}

void SportsCarBuilder::buildBody() {
    product->parts_.emplace_back("Coupe");
}

Product* SportsCarBuilder::GetProduct() {
    return product;
}
