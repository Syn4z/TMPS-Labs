cmake_minimum_required(VERSION 3.10)

project(CarManufacturerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCES
    src/carManufacturing/PersonalCar.cpp
    src/marketing/Advertisements.cpp
    Main.cpp
)

# Define header files
set(HEADERS
    include/carManufacturing/PersonalCar.h
    include/marketing/Advertisements.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Specify include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)
