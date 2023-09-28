#include "../../include/assembly-line/ElectricCarBuilder.h"
#include "../../include/assembly-line/Product.h"

ElectricCarBuilder::ElectricCarBuilder() {
    product = new Product();
}

ElectricCarBuilder::~ElectricCarBuilder() {
    delete product;
}

void ElectricCarBuilder::buildEngine() {
    product->parts_.push_back("2 AC synchronous electric motors");
}

void ElectricCarBuilder::buildTransmission() {
    product->parts_.push_back("2-speed automatic (AWD)");
}

void ElectricCarBuilder::buildCarSuspension() {
    product->parts_.push_back("Air suspension");
}

void ElectricCarBuilder::buildSteering() {
    product->parts_.push_back("4D Chassis Control");
}

void ElectricCarBuilder::buildBody() {
    product->parts_.push_back("Sedan");
}

Product* ElectricCarBuilder::GetProduct() {
    return product;
}