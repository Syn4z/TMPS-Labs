#include "../../include/user/Menu.h"

Menu::Menu(std::vector<std::shared_ptr<CarInterface>>& cars, std::vector<std::shared_ptr<CarImpl>> &commercialCars, std::vector<FreeAdvertisementImpl> &freeAds, std::vector<PaidAdvertisementImpl> &paidAds)
    : cars(cars), commercialCars(commercialCars), freeAds(freeAds), paidAds(paidAds) {}

void Menu::run() {
    bool exitProgram = false;
    while (!exitProgram) {
        int mainChoice = showMainMenu();
        switch (mainChoice) {
            case 1:
                handleCarInformation();
                break;
            case 2:
                handleMarketingInformation();
                break;
            case 3:
                handleProductionInformation();
                break;
            case 4:
                handleStaffInformation();
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

int Menu::showMainMenu() {
    int mainChoice;
    std::cout << "\nMain Menu Options:" << std::endl
              << "1. Car Information" << std::endl
              << "2. Marketing Information" << std::endl
              << "3. Production Information" << std::endl
              << "4. Staff Information" << std::endl
              << "5. Exit" << std::endl
              << "Enter your choice: ";
    std::cin >> mainChoice;
    return mainChoice;
}

void Menu::handleCarInformation() {
    int carChoice;
    cars.push_back(std::make_shared<CarImpl>("Toyota", "Camry", 2023, "Advanced Safety Suite, Touchscreen Infotainment, Keyless Entry", 25000.0, 11, "T2023C001-P"));
    cars.push_back(std::make_shared<CarImpl>("Honda", "Civic", 2022, "Lane Keeping Assist, Apple CarPlay, Android Auto", 20000.0, 10, "H2022C002-P"));
    cars.push_back(std::make_shared<CarImpl>("Nissan", "Altima", 2021, "Towing Package, Sync 4 Infotainment, Remote Start", 15000.0, 12, "N2021A003-P"));
    cars.push_back(std::make_shared<CarImpl>("Ford", "Fusion", 2020, "Blind Spot Monitoring, Wireless Charging, Rearview Camera", 10000.0, 15, "F2020F004-P"));
    commercialCars.push_back(std::make_shared<CommercialCar>("Toyota", "Tundra", 2021, "POWER", 25000.0, 11, "T2123C001-CM"));
    while (true) {
        std::cout << "\nCar Information Menu:" << std::endl
                  << "1. Display Car Information" << std::endl
                  << "2. Change Car Quantity" << std::endl
                  << "3. Tune a Car" << std::endl
                  << "4. Back to Main Menu" << std::endl
                  << "Enter your choice: ";
        std::cin >> carChoice;
        std::string title;
        std::string serialNr;
        int newQuantity;
        std::string input;
        bool carFound = false;
        DetailedCarInfo detailedStrategy;
        SummaryCarInfo summaryStrategy;
        CarInfoDisplay detailedDisplay(detailedStrategy);
        CarInfoDisplay summaryDisplay(summaryStrategy);

        switch (carChoice) {
            case 1:
                while (true) {
                    std::cout << "Enter the serial nr of the car/Enter 'A' for all cars: ";
                    std::cin >> serialNr;
                    if (serialNr.size() != 12 && serialNr.size() != 11 && serialNr != "A") {
                        std::cout << "Invalid serial number. Serial number must have exactly 11/12 characters."
                                  << std::endl;
                        continue;
                    } else {
                        break;
                    }
                }
                for (const auto& commercialCar : commercialCars) {
                    CarCosts commercialCarCosts(*commercialCar);
                    commercialCar->setType();
                    detailedDisplay.displayCarInfo(*commercialCar);
                    if (serialNr != "A" && commercialCar->getSerialNr() == serialNr) {
                        commercialCarCosts.display();
                    }
                    double profit = commercialCarCosts.calculateProfit();
                    double costPrice = commercialCarCosts.getAllCosts();
                    std::cout << "\nAll Expenses: $" << costPrice << std::endl;
                    std::cout << "Profit: $" << profit << std::endl;
                    std::cout << "--------------------------" << std::endl;
                }
                for (auto &car: cars) {
                    if (car->getSerialNr() == serialNr || serialNr == "A") {
                        car->setType();
                        std::cout << "\n  Car Information:" << std::endl;
                        CarCosts carCosts(*car);
                        double profit = carCosts.calculateProfit();
                        double costPrice = carCosts.getAllCosts();
                        if (serialNr != "A" && car->getSerialNr() == serialNr) {
                            detailedDisplay.displayCarInfo(*car);
                            carCosts.display();
                        }
                        else {
                            summaryDisplay.displayCarInfo(*car);
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
                for (auto& car : cars) {
                    if (car->getSerialNr() == serialNr) {
                        car = std::make_shared<TunedCarDecorator>(car);
                        car->setType();
                        std::cout << "Car with serial number '" << serialNr << "' tuned." << std::endl;
                        carFound = true;
                        break;
                    }
                }
                if (!carFound) {
                    std::cout << "Car with serial number '" << serialNr << "' not found." << std::endl;
                }
                break;

            case 4:
                break;

            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
        if (carChoice == 4) {
            break;
        }
    }
}

void Menu::handleMarketingInformation() {
    int marketingChoice;
    Customer& customer = Customer::GetInstance("John Doe", 30);
    while (true) {
        std::cout << "\nMarketing Information Menu:" << std::endl
                << "1. Add Advertisement" << std::endl
                << "2. Show Advertisements" << std::endl
                << "3. Search Advertisement" << std::endl
                << "4. Display Customer Availability" << std::endl
                << "5. Back to Main Menu" << std::endl
                << "Enter your choice: ";
        std::cin >> marketingChoice;
        std::string searchTitle;
        std::string serialNr;
        std::string input;
        std::string costInput;
        std::string feedbackInput;
        std::string title;
        std::string content;
        Advertiser advertiser;
        ConcreteObserver observer;
        advertiser.registerObserver(&observer);

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
                    Notification ad(content);
                    advertiser.notifyObservers(ad);
                }
                else if (input == "paid") {
                    paidAds.emplace_back(title, content, std::stod(costInput), std::stoi(feedbackInput));
                    Notification ad(content);
                    advertiser.notifyObservers(ad);
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
                        if (ad.receiveAdvertisement(&customer)) {
                            std::cout << customer.GetName() << " is eligible for this ad." << std::endl;
                        }
                        else {
                            std::cout << customer.GetName() << " is NOT eligible for this ad." << std::endl;
                        }
                }
                for (const auto& ad : paidAds) {
                    std::cout << "\n  Paid Advertisement: " << ad.getTitle() << std::endl;
                        if (ad.receiveAdvertisement(&customer, 21)) {
                            std::cout << customer.GetName() << " is eligible for this ad." << std::endl;
                        }
                        else {
                            std::cout << customer.GetName() << " is NOT eligible for this ad." << std::endl;
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
}

void Menu::handleProductionInformation() {
    int productionChoice;
    SportsCarBuilder sportsCar;
    OffroadCarBuilder offroadCar;
    ElectricCarBuilder electricCar;
    auto* porsche911 = new Product(*Assembly::SupplyProduct(sportsCar));
    auto* toyotaTacoma = new Product(*Assembly::SupplyProduct(offroadCar));
    auto* porscheTaycan = new Product(*Assembly::SupplyProduct(electricCar));
    CarFactory* sedanFactory = new SedanFactory();
    CarFactory* suvFactory = new SUVFactory();
    while (true) {
        std::cout << "\nProduction Information Menu:" << std::endl
                << "1. Build vehicle parts" << std::endl
                << "2. View assembled vehicles on factory" << std::endl
                << "3. Back to Main Menu" << std::endl
                << "Enter your choice: ";
        std::cin >> productionChoice;

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
        if (productionChoice == 3) {
            break;
        }
    }
    delete sedanFactory;
    delete suvFactory;
    delete porsche911;
    delete toyotaTacoma;
    delete porscheTaycan;
}

void Menu::handleStaffInformation() {
    int staffChoice;
    Employee* worker1 = new Worker("John");
    Employee* worker2 = new Worker("Alice");
    Employee* supervisor = new Supervisor("Dumitruta");
    while (true) {
        std::cout << "\nStaff Information Menu:" << std::endl
                << "1. Display Staff Information" << std::endl
                << "2. Back to Main Menu" << std::endl
                << "Enter your choice: ";
        std::cin >> staffChoice;
        supervisor->addEmployee(worker1);
        supervisor->addEmployee(worker2);

        switch (staffChoice) {
            case 1:
                std::cout << "\n  Staff Information:" << std::endl;
                supervisor->work();
                break;

            case 2:
                break;

            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
        if (staffChoice == 2) {
            break;
        }
    }
}

bool Menu::isValidDoubleInput(const std::string& input) {
    std::istringstream stream(input);
    double value;
    return stream >> value && stream.eof();
}

void
Menu::ClientCode(const CarFactory &factory, std::string brand, std::string model, int year, std::string features,
                 double price, int quantity, std::string serialNr) {
    CarInterface* car = factory.CreateCar(std::move(brand), std::move(model), year, std::move(features), price, quantity, std::move(serialNr));
    car->setType();
    DetailedCarInfo detailedStrategy;
    CarInfoDisplay detailedDisplay(detailedStrategy);
    detailedDisplay.displayCarInfo(*car);
    delete car;
}
