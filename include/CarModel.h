#include <string>

class CarModel {
public:
    // Constructor to initialize the attributes
    CarModel(std::string name, int year, double price);

    // Method to set or update the features of the car model
    void setFeatures(std::string newFeatures);

    // Method to calculate the profit for the car model
    double calculateProfit(double costPrice) const;

    // Method to display information about the car model
    void displayInfo() const;

private:
    // Private member variables
    std::string name;
    int year;
    double price;
    std::string features;
};
