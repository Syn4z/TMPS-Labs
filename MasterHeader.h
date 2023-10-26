#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <limits>
#include "include/carManufacturing/CarInfoDisplay.h"
#include "include/carManufacturing/CarCosts.h"
#include "include/carManufacturing/CommercialCar.h"
#include "include/marketing/Customer.h"
#include "include/marketing/FreeAdvertisementDisplay.h"
#include "include/marketing/PaidAdvertisementDisplay.h"
#include "include/assembly-line/Product.h"
#include "include/assembly-line/builder/CarBuilder.h"
#include "include/assembly-line/builder/SportsCarBuilder.h"
#include "include/assembly-line/builder/OffroadCarBuilder.h"
#include "include/assembly-line/builder/ElectricCarBuilder.h"
#include "include/assembly-line/Assembly.h"
#include "include/carManufacturing/factory/SedanFactory.h"
#include "include/carManufacturing/factory/SUVFactory.h"
#include "include/carManufacturing/CarDecorator.h"
#include "include/carManufacturing/TunedCarDecorator.h"
#include "include/carManufacturing/OffroadCar.h"
#include "include/carManufacturing/SedanActions.h"
#include "include/carManufacturing/SUVActions.h"
#include "include/personnel/Worker.h"
#include "include/personnel/Supervisor.h"
#include "include/user/Menu.h"

