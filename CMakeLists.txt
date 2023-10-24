cmake_minimum_required(VERSION 3.10)

project(CarManufacturerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Main.cpp
    src/carManufacturing/CarImpl.cpp
    src/carManufacturing/CarCosts.cpp
    src/marketing/FreeAdvertisementImpl.cpp
    src/marketing/PaidAdvertisementImpl.cpp
    src/marketing/FreeAdvertisementDisplay.cpp
    src/marketing/PaidAdvertisementDisplay.cpp
    src/marketing/Customer.cpp
    src/assembly-line/Product.cpp
    src/assembly-line/builder/SportsCarBuilder.cpp
    src/assembly-line/builder/OffroadCarBuilder.cpp
    src/assembly-line/Assembly.cpp
    src/assembly-line/builder/ElectricCarBuilder.cpp
    src/carManufacturing/factory/Sedan.cpp
    src/carManufacturing/factory/SUV.cpp
    src/carManufacturing/factory/SedanFactory.cpp
    src/carManufacturing/factory/SUVFactory.cpp
    src/carManufacturing/CarDecorator.cpp
    src/carManufacturing/TunedCarDecorator.cpp
    src/carManufacturing/SedanActions.cpp
    src/carManufacturing/SUVActions.cpp
    src/carManufacturing/CivilCar.cpp
    src/carManufacturing/OffroadCar.cpp
    src/personnel/Worker.cpp
    src/personnel/Supervisor.cpp
    src/user/MenuFacade.cpp
)

set(HEADERS
    MasterHeader.h
    include/carManufacturing/CarInterface.h
    include/marketing/Advertisement.h
    include/marketing/FreeAdvertisement.h
    include/marketing/PaidAdvertisement.h
    include/marketing/FreeAdvertisementImpl.h
    include/marketing/PaidAdvertisementImpl.h
    include/carManufacturing/factory/Sedan.h
    include/carManufacturing/factory/SUV.h
    include/carManufacturing/factory/CarFactory.h
    include/carManufacturing/factory/SedanFactory.h
    include/carManufacturing/factory/SUVFactory.h
    include/personnel/Employee.h
    include/carManufacturing/CarDecorator.h
    include/carManufacturing/TunedCarDecorator.h
    include/carManufacturing/CarActions.h
    include/carManufacturing/SedanActions.h
    include/carManufacturing/SUVActions.h
    include/carManufacturing/CivilCar.h
    include/carManufacturing/OffroadCar.h
    include/personnel/Worker.h
    include/personnel/Supervisor.h
    include/user/MenuFacade.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)
