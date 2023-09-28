cmake_minimum_required(VERSION 3.10)

project(CarManufacturerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Main.cpp
    src/carManufacturing/CarImpl.cpp
        src/carManufacturing/CommercialCar.cpp
    src/carManufacturing/CarInfoDisplay.cpp
    src/carManufacturing/CarCosts.cpp
    src/marketing/FreeAdvertisementImpl.cpp
    src/marketing/PaidAdvertisementImpl.cpp
    src/marketing/FreeAdvertisementDisplay.cpp
    src/marketing/PaidAdvertisementDisplay.cpp
        src/marketing/Customer.cpp
)

set(HEADERS
    include/carManufacturing/Car.h
    include/marketing/Advertisement.h
    include/marketing/FreeAdvertisement.h
    include/marketing/PaidAdvertisement.h
        include/marketing/Customer.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)
