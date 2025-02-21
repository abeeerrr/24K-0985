#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool availability;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        availability = true;
    }

    Car(string newBrand, string newModel, double newPrice, bool isAvailable) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
        availability = isAvailable;
    }

    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        rentalPrice = other.rentalPrice;
        availability = other.availability;
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
        cout << "Car rented successfully for " << days << " days. Final rental price: $" << finalPrice << endl;
    }

    void displayCarDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Availability: " << (checkAvailability() ? "Available" : "Rented") << endl;
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
    
    return 0;
}