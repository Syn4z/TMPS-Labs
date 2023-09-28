#include "../../include/assembly-line/Assembly.h"
#include "../../include/assembly-line/CarBuilder.h"

Product* Assembly::SupplyProduct(CarBuilder& builder) {
    builder.buildEngine();
    builder.buildTransmission();
    builder.buildCarSuspension();
    builder.buildSteering();
    builder.buildBody();
    return builder.GetProduct();
}