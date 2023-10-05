#include "MasterHeader.h"

void ClientCode(const CarFactory& factory, std::string brand, std::string model, int year, std::string features, double price, int quantity, std::string serialNr) {
    CarInterface* car = factory.CreateCar(std::move(brand), std::move(model), year, std::move(features), price, quantity, std::move(serialNr));
    car->setType();
    CarInfoDisplay car1(*car);
    car1.display();
    delete car;
}

bool isValidDoubleInput(const std::string& input) {
    std::istringstream stream(input);
    double value;
    return stream >> value && stream.eof();
}

int main() {
    bool exitProgram = false;
    // Cars
    std::vector<std::shared_ptr<CarImpl>> cars;
    std::vector<std::shared_ptr<CarImpl>> commercialCars;
    // Marketing
    std::vector<FreeAdvertisementImpl> freeAds;
    std::vector<PaidAdvertisementImpl> paidAds;
    std::vector<Customer*> customers;
    [[maybe_unused]] Customer* customer1 = Customer::GetInstance("John Doe", 30);
    [[maybe_unused]] Customer* customer2 = Customer::GetInstance("Mark Yeet", 16);
    [[maybe_unused]] Customer* customer3 = Customer::GetInstance("Jane Doe", 20);
    [[maybe_unused]] Customer* customer4 = Customer::GetInstance("John Doe", 17);
    std::vector<Customer*> allCustomers = Customer::GetAllCustomers();
    // Production
    SportsCarBuilder sportsCar;
    OffroadCarBuilder offroadCar;
    ElectricCarBuilder electricCar;
    // Staff
    EmployeeFactory employeeFactory;

    while (!exitProgram) {
        int mainChoice;
        std::cout << "\nMain Menu Options:" << std::endl;
        std::cout << "1. Car Information" << std::endl;
        std::cout << "2. Marketing Information" << std::endl;
        std::cout << "3. Production Information" << std::endl;
        std::cout << "4. Staff Information" << std::endl;
        std::cout << "5. Exit" << std::endl;
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
                    cars.push_back(std::make_shared<CarImpl>("Toyota", "Camry", 2023, "Advanced Safety Suite, Touchscreen Infotainment, Keyless Entry", 25000.0, 11, "T2023C001-P"));
                    cars.push_back(std::make_shared<CarImpl>("Honda", "Civic", 2022, "Lane Keeping Assist, Apple CarPlay, Android Auto", 20000.0, 10, "H2022C002-P"));
                    cars.push_back(std::make_shared<CarImpl>("Nissan", "Altima", 2021, "Towing Package, Sync 4 Infotainment, Remote Start", 15000.0, 12, "N2021A003-P"));
                    cars.push_back(std::make_shared<CarImpl>("Ford", "Fusion", 2020, "Blind Spot Monitoring, Wireless Charging, Rearview Camera", 10000.0, 15, "F2020F004-P"));
                    commercialCars.push_back(std::make_shared<CommercialCar>("Toyota", "Tundra", 2021, "POWER", 25000.0, 11, "T2123C001-CM"));

                    switch (carChoice) {
                        case 1:
                            while (true) {
                                std::cout << "Enter the serial nr of the car/Enter 'A' for all cars: ";
                                std::cin >> serialNr;
                                if (serialNr.size() != 12 && serialNr.size() != 11 && serialNr != "A") {
                                    std::cout << "Invalid serial number. Serial number must have exactly 11/12 characters." << std::endl;
                                    continue;
                                }
                                else {
                                    break;
                                }
                            }
                            for (const auto& commercialCar : commercialCars) {
                                CarInfoDisplay commercialCarInfoDisplay(*commercialCar);
                                CarCosts commercialCarCosts(*commercialCar);
                                commercialCar->setType();
                                commercialCarInfoDisplay.display();
                                if (serialNr != "A" && commercialCar->getSerialNr() == serialNr) {
                                    commercialCarCosts.display();
                                }
                                double profit = commercialCarCosts.calculateProfit();
                                double costPrice = commercialCarCosts.getAllCosts();
                                std::cout << "\nAll Expenses: $" << costPrice << std::endl;
                                std::cout << "Profit: $" << profit << std::endl;
                                std::cout << "--------------------------" << std::endl;
                            }
                            for (auto& car : cars) {
                                if (car->getSerialNr() == serialNr || serialNr == "A") {
                                    car->setType();
                                    std::cout << "\n  Car Information:" << std::endl;
                                    CarInfoDisplay carInfoDisplay(*car);
                                    CarCosts carCosts(*car);
                                    carInfoDisplay.display();
                                    double profit = carCosts.calculateProfit();
                                    double costPrice = carCosts.getAllCosts();
                                    if (serialNr != "A" && car->getSerialNr() == serialNr) {
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
                                std::cin >> serialNr;
                                if (serialNr.size() == 11 || serialNr.size() == 12 && serialNr.find(' ') == std::string::npos) {
                                    break;
                                }
                                else {
                                    std::cout << "Invalid serial number. Serial number must have exactly 11/12 characters." << std::endl;
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
                                    if (car->getSerialNr() == serialNr) {
                                        car->setQuantity(newQuantity);
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
                    std::cout << "4. Display Customer Availability" << std::endl;
                    std::cout << "5. Back to Main Menu" << std::endl;
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
                                    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
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
                                freeAds.emplace_back(title, content, std::stoi(feedbackInput));
                            }
                            else if (input == "paid") {
                                paidAds.emplace_back(title, content, std::stod(costInput), std::stoi(feedbackInput));
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
                            for (const auto& freeAd : freeAds) {
                                if (freeAd.getTitle() == searchTitle) {
                                    FreeAdvertisementDisplay adsDisplay(freeAd);
                                    adsDisplay.displayAd();
                                    std::cout << "Do you want to delete this advertisement? (Y/N): ";
                                    std::cin >> input;
                                    if (input == "Y") {
                                        freeAds.erase(freeAds.begin() + (&freeAd - &freeAds[0]));
                                        std::cout << "Advertisement deleted." << std::endl;
                                        break;
                                    }
                                    else if (input == "N") {
                                        break;
                                    }
                                }
                                else {
                                    for (const auto& paidAd : paidAds) {
                                        if (paidAd.getTitle() == searchTitle) {
                                            PaidAdvertisementDisplay adsDisplay(paidAd);
                                            adsDisplay.displayAd();
                                            std::cout << "Do you want to delete this advertisement? (Y/N): ";
                                            std::cin >> input;
                                            if (input == "Y") {
                                                paidAds.erase(paidAds.begin() + (&paidAd - &paidAds[0]));
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

                        case 4:
                            for (const auto& ad : freeAds) {
                                std::cout << "\n  Free Advertisement: " << ad.getTitle() << std::endl;
                                for (auto customer : allCustomers)
                                {
                                    if (ad.receiveAdvertisement(customer)) {
                                        std::cout << customer->GetName() << " is eligible for this ad." << std::endl;
                                    }
                                    else {
                                        std::cout << customer->GetName() << " is NOT eligible for this ad." << std::endl;
                                    }
                                }
                            }
                            for (const auto& ad : paidAds) {
                                std::cout << "\n  Paid Advertisement: " << ad.getTitle() << std::endl;
                                for (auto customer : allCustomers)
                                {
                                    if (ad.receiveAdvertisement(customer, 21)) {
                                        std::cout << customer->GetName() << " is eligible for this ad." << std::endl;
                                    }
                                    else {
                                        std::cout << customer->GetName() << " is NOT eligible for this ad." << std::endl;
                                    }
                                }
                            }
                            break;

                        case 5:
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                    }
                    if (marketingChoice == 5) {
                        break;
                    }
                }
                break;

            case 3: // Production Information Menu
                while (true) {
                    int productionChoice;
                    std::cout << "\nProduction Information Menu:" << std::endl;
                    std::cout << "1. Build vehicle parts" << std::endl;
                    std::cout << "2. View assembled vehicles on factory" << std::endl;
                    std::cout << "3. Back to Main Menu" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> productionChoice;
                    auto* porsche911 = new Product(*Assembly::SupplyProduct(sportsCar));
                    auto* toyotaTacoma = new Product(*Assembly::SupplyProduct(offroadCar));
                    auto* porscheTaycan = new Product(*Assembly::SupplyProduct(electricCar));
                    CarFactory* sedanFactory = new SedanFactory();
                    CarFactory* suvFactory = new SUVFactory();

                    switch (productionChoice) {
                        case 1:
                            std::cout << "\n  Parts built:" << std::endl;
                            std::cout << "Porsche 911 parts: ";
                            porsche911->ShowParts();
                            std::cout << "\nToyota Tacoma parts: ";
                            toyotaTacoma->ShowParts();
                            std::cout << "\nPorsche Taycan parts: ";
                            porscheTaycan->ShowParts();
                            break;

                        case 2:
                            std::cout << "\n  Factory Produced:\n" << std::endl;
                            ClientCode(*sedanFactory, "Toyota", "Camry", 2023, "Advanced Safety Suite, Touchscreen Infotainment, Keyless Entry", 25000.0, 11, "T2023C001-P");
                            std::cout << std::endl;
                            ClientCode(*sedanFactory, "Nissan", "Altima", 2021, "Towing Package, Sync 4 Infotainment, Remote Start", 15000.0, 12, "N2021A003-P");
                            std::cout << std::endl;
                            ClientCode(*suvFactory, "Honda", "Civic", 2022, "Lane Keeping Assist, Apple CarPlay, Android Auto", 20000.0, 10, "H2022C002-P");
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                    }
                    delete sedanFactory;
                    delete suvFactory;
                    delete porsche911;
                    delete toyotaTacoma;
                    delete porscheTaycan;
                    if (productionChoice == 3) {
                        break;
                    }
                }
                break;

            case 4: // Staff Information Menu
                while (true) {
                    int staffChoice;
                    std::cout << "\nStaff Information Menu:" << std::endl;
                    std::cout << "1. Display Staff Information" << std::endl;
                    std::cout << "2. Back to Main Menu" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> staffChoice;
                    Employee* manager = employeeFactory.CreateEmployee(MANAGER);
                    Employee* developer = employeeFactory.CreateEmployee(DEVELOPER);

                    switch (staffChoice) {
                        case 1:
                            std::cout << "\n  Staff Information:" << std::endl;
                            manager->Display();
                            std::cout << "\n";
                            developer->Display();
                            break;

                        case 2:
                            break;

                        default:
                            std::cout << "Invalid choice. Try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                    }
                    delete manager;
                    delete developer;
                    if (staffChoice == 2) {
                        break;
                    }
                }
                break;

            case 5:
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
