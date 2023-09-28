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
    src/assembly-line/SportsCarBuilder.cpp
    src/assembly-line/OffroadCarBuilder.cpp
    src/assembly-line/Assembly.cpp
    src/assembly-line/ElectricCarBuilder.cpp
)

set(HEADERS
    MasterHeader.h
    include/carManufacturing/Car.h
    include/marketing/Advertisement.h
    include/marketing/FreeAdvertisement.h
    include/marketing/PaidAdvertisement.h
    include/marketing/FreeAdvertisementImpl.h
    include/marketing/PaidAdvertisementImpl.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)
