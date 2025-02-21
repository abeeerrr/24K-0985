#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool availability;
    double totalRevenue;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        availability = true;
        totalRevenue = 0.0;
    }

    Car(string newBrand, string newModel, double newPrice, bool isAvailable) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
        availability = isAvailable;
        totalRevenue = 0.0;
    }

    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        rentalPrice = other.rentalPrice;
        availability = other.availability;
        totalRevenue = other.totalRevenue;
    }
    ~Car() {
        cout << "Car object with brand " << brand << " is being destroyed." << endl;
    }

    void updateCarDetails(string newBrand, string newModel, double newPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }

    bool checkAvailability() const {
        return availability;
    }

    double applyDiscount(int days) {
        if (days > 10) {
            return rentalPrice * 0.9; 
        } else if (days > 5) {
            return rentalPrice * 0.95; 
        }
        return rentalPrice;
    }
    void rentCar(int days) {
        if (!checkAvailability()) {
            cout << "Car is not available for rent!" << endl;
            return;
        }
        availability = false;
        double finalPrice = applyDiscount(days);
        totalRevenue += finalPrice * days;
        cout << "Car rented successfully for " << days << " days. Final rental price per day: $" << finalPrice << endl;
    }

    void displayCarDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Availability: " << (checkAvailability() ? "Available" : "Rented") << endl;
        cout << "Total Revenue: $" << totalRevenue << endl;
    }
};

int main() {
    Car myCar("GMC", "Acadia", 50.0, true);
    myCar.displayCarDetails();
    
    cout << "Creating a copy of the car...\n";
    Car copiedCar(myCar);
    copiedCar.displayCarDetails();
    
    cout << "Updating original car details...\n";
    myCar.updateCarDetails("Honda", "Civic", 60.0);
    myCar.displayCarDetails();
    
    cout << "Verifying copied car remains unchanged...\n";
    copiedCar.displayCarDetails();
    
    cout << "Processing rental request for 7 days...\n";
    myCar.rentCar(7);
    myCar.displayCarDetails();
    
    return 0;
}