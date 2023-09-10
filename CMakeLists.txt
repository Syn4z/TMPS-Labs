cmake_minimum_required(VERSION 3.10)

project(CarManufacturerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCES
    src/carManufacturing/CarModel.cpp
    # src/CarManufacturer.cpp
    Main.cpp
)

# Define header files
set(HEADERS
    include/carManufacturing/CarModel.h
    # include/CarManufacturer.h
    # include/Interfaces/IProduction.h
    # include/Interfaces/IReporting.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Specify include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)
