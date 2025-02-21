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

    void updateCarDetails(string newBrand, string newModel, double newPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }


    bool checkAvailability() const {
        return availability;
    }

    void rentCar() {
        if (checkAvailability()) {
            availability = false;
            cout << "Car rented successfully!" << endl;
        } else {
            cout << "Car is already rented out!" << endl;
        }
    }

    void displayCarDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Availability: " << (checkAvailability() ? "Available" : "Rented") << endl;
    }
};

int main() {
    Car myCar;
    myCar.displayCarDetails();
    
    cout << "Updating car details...\n";
    myCar.updateCarDetails("Acadia", "GMC", 50.0);
    myCar.displayCarDetails();
    
    cout << "Processing rental request...\n";
    myCar.rentCar();
    myCar.displayCarDetails();
    
    cout << "Trying to rent again...\n";
    myCar.rentCar();
    
    return 0;
}
