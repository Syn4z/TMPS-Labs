#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include "src/carManufacturing/CarInfoDisplay.cpp"
#include "src/carManufacturing/CarCosts.cpp"
#include "src/carManufacturing/ComercialCar.cpp"
#include "src/marketing/FreeAdvertisementDisplay.cpp"
#include "src/marketing/PaidAdvertisementDisplay.cpp"


bool isValidDoubleInput(const std::string& input) {
    std::istringstream stream(input);
    double value;
    return stream >> value && stream.eof();
}

int main() {
    bool exitProgram = false;
    std::vector<CarImpl> cars;
    cars.push_back(CarImpl("Toyota", "Camry", 2023, "Advanced Safety Suite, Touchscreen Infotainment, Keyless Entry", 25000.0, 11, "T2023C001"));
    cars.push_back(CarImpl("Honda", "Civic", 2022, "Lane Keeping Assist, Apple CarPlay, Android Auto", 20000.0, 10, "H2022C002"));
    cars.push_back(CarImpl("Nissan", "Altima", 2021, "Towing Package, Sync 4 Infotainment, Remote Start", 15000.0, 12, "N2021A003"));
    cars.push_back(CarImpl("Ford", "Fusion", 2020, "Blind Spot Monitoring, Wireless Charging, Rearview Camera", 10000.0, 15, "F2020F004"));
    ComercialCar comercialCar("Toyota", "Tundra", 2021, "POWER", 25000.0, 11, "T2123C001", "FireTruck");
    CarInfoDisplay comercialCarInfoDisplay(comercialCar);
    CarCosts comercialCarCosts(comercialCar);
    double profit = comercialCarCosts.calculateProfit();
    double costPrice = comercialCarCosts.getAllCosts();

    std::vector<FreeAdvertisementImpl> freeAds;
    std::vector<PaidAdvertisementImpl> paidAds;

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
                            while (true) {
                                std::cout << "Enter the serial nr of the car/Enter 'A' for all cars: ";
                                std::cin >> serialNr;
                                if (serialNr.size() != 9 && serialNr != "A") {
                                    std::cout << "Invalid serial number. Serial number must have exactly 9 characters." << std::endl;
                                    continue;
                                }
                                else {
                                    break;
                                }
                            }
                            std::cout << "!!!!! Comercial Car Information !!!!!\n";
                            comercialCarInfoDisplay.display();
                            std::cout << comercialCar.getType() << std::endl;
                            if (serialNr != "A" && comercialCar.getSerialNr() == serialNr) {
                                comercialCarCosts.display();
                            }
                            std::cout << "\nAll Expenses: $" << costPrice << std::endl;
                            std::cout << "Profit: $" << profit << std::endl;
                            std::cout << "--------------------------" << std::endl;
                            for (const auto& car : cars) {
                                if (car.getSerialNr() == serialNr || serialNr == "A") {
                                    std::cout << "\n  Car Information:" << std::endl;
                                    CarInfoDisplay carInfoDisplay(car);
                                    CarCosts carCosts(car);
                                    carInfoDisplay.display();
                                    double profit = carCosts.calculateProfit();
                                    double costPrice = carCosts.getAllCosts();
                                    if (serialNr != "A" && car.getSerialNr() == serialNr) {
                                        carCosts.display();
                                    }
                                    std::cout << "\nAll Expenses: $" << costPrice << std::endl;
                                    std::cout << "Profit: $" << profit << std::endl;
                                    std::cout << "--------------------------" << std::endl;
                                    carFound = true;

                                    if (serialNr != "A") {
                                        break;
                                    }
                                }
                            } 
                            if (!carFound) {
                                std::cout << "Car with serial number " << serialNr << " not found." << std::endl;
                            }   
                            break;

                        case 2:
                            while (true) {
                                std::cout << "Enter the serial nr of the car:\n";
                                std::getline(std::cin, serialNr);
                                if (serialNr.size() == 9 && serialNr.find(' ') == std::string::npos) {
                                    break;
                                }
                                else {
                                    std::cout << "Invalid serial number. Serial number must have exactly 9 characters." << std::endl;
                                }
                            }
                            while (true) {
                                std::cout << "Enter the new quantity as an integer: ";
                                std::cin >> input;
                                try {
                                    newQuantity = std::stoi(input); 
                                    break;
                                } catch (std::invalid_argument&) {
                                    std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
                                } catch (std::out_of_range&) {
                                    std::cerr << "Input out of range for integer. Please enter a valid integer." << std::endl;
                                }
                            }
                            try {
                                for (auto& car : cars) {
                                    if (car.getSerialNr() == serialNr) {
                                        car.setQuantity(newQuantity);
                                        std::cout << "Quantity updated for car with serial number " << serialNr << std::endl;
                                        carFound = true;
                                        break;
                                    }
                                }
                                if (!carFound) {
                                    throw std::invalid_argument("Car with serial number '" + serialNr + "' not found.");
                                }
                            } catch (const std::exception& e) {
                                std::cerr << "An error occurred: " << e.what() << std::endl;
                            }
                            break;

                        case 3:
                            break;

                        default:
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    std::string costInput;
                    std::string feedbackInput;
                    std::string title;
                    std::string content;

                    switch (marketingChoice) {
                        case 1:
                            while (true) {
                                std::cout << "Enter the type of advertisement (Free/Paid): ";
                                std::cin >> input;

                                for (char& c : input) {
                                    c = std::tolower(c);
                                }

                                if (input == "free" || input == "paid") {
                                    break;
                                } else {
                                    std::cout << "Invalid input. Please enter 'Free' or 'Paid'." << std::endl;
                                }
                            }
                            std::cout << "Enter the title: ";
                            std::cin.ignore();
                            std::getline(std::cin, title);
                            std::cout << "Enter the content: ";
                            std::getline(std::cin, content);
                            if (input == "paid") {
                                do {
                                    std::cout << "Enter the cost: ";
                                    std::getline(std::cin, costInput);
                                } while (!isValidDoubleInput(costInput));
                            }
                            while (true) { 
                                std::cout << "Enter the feedback: ";
                                std::getline(std::cin, feedbackInput);
                                try {
                                    std::stoi(feedbackInput);
                                    break;
                                } catch (const std::invalid_argument& e) {
                                    std::cerr << "Invalid input. Please enter an integer." << std::endl;
                                }
                            }
                            if (input == "free") {
                                freeAds.push_back(FreeAdvertisementImpl(title, content, std::stoi(feedbackInput)));
                            }
                            else if (input == "paid") {
                                paidAds.push_back(PaidAdvertisementImpl(title, content, std::stod(costInput), std::stoi(feedbackInput)));
                            }
                            break;

                        case 2:
                            if (freeAds.empty() && paidAds.empty()) {
                                std::cout << "No ads to display." << std::endl;
                                break;
                            }
                            if (!freeAds.empty()) {
                                std::cout << "\n  Free Advertisements:" << std::endl;
                                for (const auto& ad : freeAds) {
                                    FreeAdvertisementDisplay adsDisplay(ad);
                                    adsDisplay.displayAd();
                                }
                            }
                            else {
                                std::cout << "No free ads to display." << std::endl;
                            }
                            if (!paidAds.empty()) {
                                std::cout << "\n  Paid Advertisements:" << std::endl;
                                for (const auto& ad : paidAds) {
                                    PaidAdvertisementDisplay adsDisplay(ad);
                                    adsDisplay.displayAd();
                                }
                            }
                            else {
                                std::cout << "No paid ads to display." << std::endl;
                            }
                            break;

                        case 3:
                            std::cout << "Enter advertisement Title: ";
                            std::cin.ignore();
                            std::getline(std::cin, searchTitle);
                            if (freeAds.empty() && paidAds.empty()) {
                                std::cout << "No advertisements available." << std::endl;
                                continue;
                            }
                            for (const auto& ad : freeAds) {
                                if (ad.getTitle() == searchTitle) {
                                    FreeAdvertisementDisplay adsDisplay(ad);
                                    adsDisplay.displayAd();
                                    std::cout << "Do you want to delete this advertisement? (Y/N): ";
                                    std::cin >> input;
                                    if (input == "Y") {
                                        freeAds.erase(freeAds.begin() + (&ad - &freeAds[0])); 
                                        std::cout << "Advertisement deleted." << std::endl;
                                        break;
                                    }
                                    else if (input == "N") {
                                        break;
                                    }
                                }
                                else {
                                    for (const auto& ad : paidAds) {
                                        if (ad.getTitle() == searchTitle) {
                                            PaidAdvertisementDisplay adsDisplay(ad);
                                            adsDisplay.displayAd();
                                            std::cout << "Do you want to delete this advertisement? (Y/N): ";
                                            std::cin >> input;
                                            if (input == "Y") {
                                                paidAds.erase(paidAds.begin() + (&ad - &paidAds[0])); 
                                                std::cout << "Advertisement deleted." << std::endl;
                                                break;
                                            }
                                            else if (input == "N") {
                                                break;
                                            }
                                        }
                                        else {
                                            std::cout << "Advertisement with title '" << searchTitle << "' not found." << std::endl;
                                        }
                                    }
                                }
                            }
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }      

    return 0;
}
