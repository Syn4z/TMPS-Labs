#include "assembly-line/builder/ElectricCarBuilder.h"

ElectricCarBuilder::ElectricCarBuilder() {
    product = new Product();
}

ElectricCarBuilder::~ElectricCarBuilder() {
    delete product;
}

void ElectricCarBuilder::buildEngine() {
    product->parts_.emplace_back("2 AC synchronous electric motors");
}

void ElectricCarBuilder::buildTransmission() {
    product->parts_.emplace_back("2-speed automatic (AWD)");
}

void ElectricCarBuilder::buildCarSuspension() {
    product->parts_.emplace_back("Air suspension");
}

void ElectricCarBuilder::buildSteering() {
    product->parts_.emplace_back("4D Chassis Control");
}

void ElectricCarBuilder::buildBody() {
    product->parts_.emplace_back("Sedan");
}

Product* ElectricCarBuilder::GetProduct() {
    return product;
}