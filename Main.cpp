#include <iostream>
#include <vector>
#include <typeinfo>
#include "include/carManufacturing/PersonalCar.h"
#include "include/marketing/Advertisements.h"


// TO DO implement SOLID principles
// Get a reason for Open-Closed Principle
// Get a reason for Liskov Substitution Principle
int main() {
    bool exitProgram = false;
    std::vector<PersonalCar> carModels;
    carModels.push_back(PersonalCar("Toyota", "Camry", 2023, "Advanced Safety Suite, Touchscreen Infotainment, Keyless Entry", 25000.0, 11, "T2023C001"));
    carModels.push_back(PersonalCar("Honda", "Civic", 2022, "Lane Keeping Assist, Apple CarPlay, Android Auto", 20000.0, 10, "H2022C002"));
    carModels.push_back(PersonalCar("Nissan", "Altima", 2021, "Towing Package, Sync 4 Infotainment, Remote Start", 15000.0, 12, "N2021A003"));
    carModels.push_back(PersonalCar("Ford", "Fusion", 2020, "Blind Spot Monitoring, Wireless Charging, Rearview Camera", 10000.0, 15, "F2020F004"));
    Advertisements ads;
    AdDetails ad;

    while (!exitProgram) {
        int mainChoice;

        std::cout << "\nMain Menu Options:" << std::endl;
        std::cout << "1. Car Information" << std::endl;
        std::cout << "2. Marketing Information" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;

        switch (mainChoice) {
            case 1: // Car Information Menu
                while (true) {
                    int carChoice;

                    std::cout << "\nCar Information Menu:" << std::endl;
                    std::cout << "1. Display Car Information" << std::endl;
                    std::cout << "2. Change Car Quantity" << std::endl;
                    std::cout << "3. Back to Main Menu" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> carChoice;
                    std::string title;
                    std::string serialNr;
                    int newQuantity;
                    std::string input;
                    bool carFound = false;

                    switch (carChoice) {
                        case 1:
                            std::cout << "Enter the serial nr of the car/Enter 'A' for all cars: ";
                            std::cin >> serialNr;
                            for (const auto& car : carModels) {
                                if (car.getSerialNr() == serialNr) {
                                    std::cout << "\n  Car Information:" << std::endl;
                                    car.displayInfo();
                                    double costPrice = car.getPrice() * 0.8;
                                    double profit = car.calculateProfit(costPrice);
                                    std::cout << "\nProduction Price: $" << costPrice << std::endl;
                                    std::cout << "Profit: $" << profit << std::endl;
                                    std::cout << "--------------------------" << std::endl;
                                    break;
                                }
                                else if (serialNr == "A") {
                                    std::cout << "  Car Information:" << std::endl;
                                    car.displayInfo();
                                    double costPrice = car.getPrice() * 0.8;
                                    double profit = car.calculateProfit(costPrice);
                                    std::cout << "\nProduction Price: $" << costPrice << std::endl;
                                    std::cout << "Profit: $" << profit << std::endl;
                                    std::cout << "--------------------------" << std::endl;
                                }
                                else {
                                    std::cout << "Car with serial number " << serialNr << " not found." << std::endl;
                                }
                            }    
                            break;

                        case 2:
                            std::cout << "Enter the serial nr of the car: ";
                            std::cin >> serialNr;
                            if (serialNr.size() != 9) {
                                std::cout << "Invalid serial number. Serial number must have exactly 9 characters." << std::endl;
                                continue;
                            }
                            std::cout << "Enter the new quantity as an integer: ";
                            std::cin >> input;
                            try {
                                newQuantity = std::stoi(input); 
                            } catch (std::invalid_argument&) {
                                std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
                                continue;
                            } catch (std::out_of_range&) {
                                std::cerr << "Input out of range for integer. Please enter a valid integer." << std::endl;
                                continue;
                            }
                            try {
                                for (auto& car : carModels) {
                                    if (car.getSerialNr() == serialNr) {
                                        car.setQuantity(newQuantity);
                                        std::cout << "Quantity updated for car with serial number " << serialNr << std::endl;
                                        car.displayInfo();
                                        carFound = true;
                                        break;
                                    }
                                }
                                if (!carFound) {
                                    throw std::invalid_argument("Car with serial number " + serialNr + " not found.");
                                }
                            } catch (const std::exception& e) {
                                std::cerr << "An error occurred: " << e.what() << std::endl;
                            }
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            break;
                    }

                    if (carChoice == 3) {
                        break;
                    }
                }
                break;

            case 2: // Marketing Information Menu
                while (true) {
                    int marketingChoice;

                    std::cout << "\nMarketing Information Menu:" << std::endl;
                    std::cout << "1. Add Advertisement" << std::endl;
                    std::cout << "2. Show Advertisements" << std::endl;
                    std::cout << "3. Search Advertisement" << std::endl;
                    std::cout << "4. Back to Main Menu" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> marketingChoice;
                    std::string searchTitle;
                    std::string serialNr;
                    std::string input;

                    switch (marketingChoice) {
                        case 1:
                            std::cout << "Enter the title: ";
                            std::cin >> ad.title;
                            std::cout << "Enter the content: ";
                            std::cin >> ad.content;
                            std::cout << "Enter the cost: ";
                            std::cin >> ad.cost;
                            std::cout << "Enter the revenue: ";
                            std::cin >> ad.revenue;
                            ads.addAdvertisement(ad);
                            break;

                        case 2:
                            std::cout << "Advertisements:" << std::endl;
                            ads.displayAllAds();
                            std::cout << "Total Profit: $" << ads.getTotalProfit() << std::endl;
                            break;

                        case 3:
                            std::cout << "Enter advertisement Title: ";
                            std::cin >> searchTitle;
                            if (ads.getAdCount() < 1) {
                                std::cout << "No advertisements available." << std::endl;
                                continue;
                            }
                            for (size_t i = 0; i < ads.getAdCount(); ++i) {
                                if (ads.getAdTitle(i) == searchTitle) {
                                    ads.displayAd(i);
                                    std::cout << "Do you want to delete this advertisement? (Y/N): ";
                                    std::cin >> input;
                                    if (input == "Y") {
                                        ads.deleteAdvertisement(i);
                                        break;
                                    }
                                    else if (input == "N") {
                                        break;
                                    }
                                }
                                else {
                                    std::cout << "Advertisement with title " << searchTitle << " not found." << std::endl;
                                }
                            }
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            break;
                    }

                    if (marketingChoice == 4) {
                        break;
                    }
                }
                break;

            case 3:
                exitProgram = true;
                break;

            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }      

    return 0;
}
