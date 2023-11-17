#include "../../include/production/Assembly.h"

Product* Assembly::SupplyProduct(CarBuilder& builder) {
    builder.buildEngine();
    builder.buildTransmission();
    builder.buildCarSuspension();
    builder.buildSteering();
    builder.buildBody();
    return builder.GetProduct();
}
