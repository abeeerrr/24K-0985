#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(string b, string m, double capacity) {
        brand = b;
        model = m;
        fuelCapacity = capacity;
        currentFuelLevel = capacity; 
    }

    void drive(double distance) {
        double fuelConsumed = distance * 0.1; 
        if (currentFuelLevel >= fuelConsumed) {
            currentFuelLevel -= fuelConsumed;
            cout << "You drove " << distance << " km. Fuel consumed: " << fuelConsumed << "L\n";
        } else {
            cout << "Not enough fuel to drive " << distance << " km. Please refuel!\n";
        }
        checkFuelStatus();
    }

    void refuel(double amount) {
        if (amount + currentFuelLevel > fuelCapacity) {
            currentFuelLevel = fuelCapacity;
            cout << "Tank is now full.\n";
        } else {
            currentFuelLevel += amount;
            cout << "Added " << amount << "L of fuel. Current fuel level: " << currentFuelLevel << "L\n";
        }
    }

    void checkFuelStatus() {
        cout << "Current Fuel Level: " << currentFuelLevel << "L\n";
        if (currentFuelLevel < 5) {
            cout << "Warning: Low fuel! Please refuel soon.\n";
        }
    }
};

int main() {
    Car myCar("Acadia", "GMC", 50);

    myCar.drive(100); 
    myCar.drive(400); 
    myCar.refuel(20);
    myCar.drive(150);

    return 0;
}
