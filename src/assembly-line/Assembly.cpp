#include "../../include/assembly-line/Assembly.h"

Product* Assembly::SupplyProduct(CarBuilder& builder) {
    builder.buildEngine();
    builder.buildTransmission();
    builder.buildCarSuspension();
    builder.buildSteering();
    builder.buildBody();
    return builder.GetProduct();
}
