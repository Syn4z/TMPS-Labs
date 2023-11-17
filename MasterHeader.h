#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <limits>
#include "vehicle/info/CarInfoDisplay.h"
#include "include/vehicle/CarCosts.h"
#include "include/vehicle/CommercialCar.h"
#include "include/marketing/Customer.h"
#include "include/marketing/FreeAdvertisementDisplay.h"
#include "include/marketing/PaidAdvertisementDisplay.h"
#include "include/production/Product.h"
#include "include/production/builder/CarBuilder.h"
#include "include/production/builder/SportsCarBuilder.h"
#include "include/production/builder/OffroadCarBuilder.h"
#include "include/production/builder/ElectricCarBuilder.h"
#include "include/production/Assembly.h"
#include "include/production/factory/SedanFactory.h"
#include "include/production/factory/SUVFactory.h"
#include "include/vehicle/CarDecorator.h"
#include "include/vehicle/TunedCarDecorator.h"
#include "vehicle/actions/OffroadCar.h"
#include "vehicle/actions/SedanActions.h"
#include "vehicle/actions/SUVActions.h"
#include "include/staff/Worker.h"
#include "include/staff/Supervisor.h"
#include "include/user/Menu.h"
#include "include/marketing/notification/Notification.h"
#include "include/marketing/notification/Advertiser.h"
#include "include/marketing/notification/ConcreteObserver.h"
#include "include/vehicle/info/DetailedCarInfo.h"
#include "include/vehicle/info/SummaryCarInfo.h"
#include "include/vehicle/CarIterator.h"
