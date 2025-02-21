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
    
    cout << "Updating car details...\n";
    myCar.updateCarDetails("Honda", "Civic", 60.0);
    myCar.displayCarDetails();
    
    cout << "Processing rental request for 7 days...\n";
    myCar.rentCar(7);
    myCar.displayCarDetails();
    
    cout << "Trying to rent again for 3 days...\n";
    myCar.rentCar(3);
    
    return 0;
}
