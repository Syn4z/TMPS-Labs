cmake_minimum_required(VERSION 3.10)

project(CarManufacturerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Main.cpp
    src/vehicle/CarImpl.cpp
    src/vehicle/CarCosts.cpp
    src/marketing/FreeAdvertisementImpl.cpp
    src/marketing/PaidAdvertisementImpl.cpp
    src/marketing/FreeAdvertisementDisplay.cpp
    src/marketing/PaidAdvertisementDisplay.cpp
    src/marketing/Customer.cpp
    src/production/Product.cpp
    src/production/builder/SportsCarBuilder.cpp
    src/production/builder/OffroadCarBuilder.cpp
    src/production/Assembly.cpp
    src/production/builder/ElectricCarBuilder.cpp
    src/production/factory/Sedan.cpp
    src/production/factory/SUV.cpp
    src/production/factory/SedanFactory.cpp
    src/production/factory/SUVFactory.cpp
    src/vehicle/CarDecorator.cpp
    src/vehicle/TunedCarDecorator.cpp
    src/vehicle/actions/SedanActions.cpp
    src/vehicle/actions/SUVActions.cpp
    src/vehicle/actions/CivilCar.cpp
    src/vehicle/actions/OffroadCar.cpp
    src/staff/Worker.cpp
    src/staff/Supervisor.cpp
    src/user/Menu.cpp
    src/vehicle/components/EngineFacade.cpp
    src/vehicle/components/IgnitionSystem.cpp
    src/vehicle/components/CoolingSystem.cpp
    src/vehicle/components/FuelSystem.cpp
    src/marketing/notification/ConcreteObserver.cpp
    src/vehicle/info/DetailedCarInfo.cpp
    src/vehicle/info/SummaryCarInfo.cpp
    src/vehicle/info/CarInfoDisplay.cpp
    src/vehicle/CarIterator.cpp
)

set(HEADERS
    MasterHeader.h
    include/vehicle/CarInterface.h
    include/marketing/Advertisement.h
    include/marketing/FreeAdvertisement.h
    include/marketing/PaidAdvertisement.h
    include/marketing/FreeAdvertisementImpl.h
    include/marketing/PaidAdvertisementImpl.h
    include/production/factory/Sedan.h
    include/production/factory/SUV.h
    include/production/factory/CarFactory.h
    include/production/factory/SedanFactory.h
    include/production/factory/SUVFactory.h
    include/staff/Employee.h
    include/vehicle/CarDecorator.h
    include/vehicle/TunedCarDecorator.h
    include/vehicle/actions/CarActions.h
    include/vehicle/actions/SedanActions.h
    include/vehicle/actions/SUVActions.h
    include/vehicle/actions/CivilCar.h
    include/vehicle/actions/OffroadCar.h
    include/staff/Worker.h
    include/staff/Supervisor.h
    include/user/Menu.h
    include/vehicle/components/FuelSystem.h
    include/vehicle/components/CoolingSystem.h
    include/vehicle/components/IgnitionSystem.h
    include/vehicle/components/EngineFacade.h
    include/marketing/notification/Notification.h
    include/marketing/notification/Observer.h
    include/marketing/notification/Advertiser.h
    include/marketing/notification/ConcreteObserver.h
    include/vehicle/info/CarInfoStrategy.h
    include/vehicle/info/DetailedCarInfo.h
    include/vehicle/info/SummaryCarInfo.h
    include/vehicle/CarIterator.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)
