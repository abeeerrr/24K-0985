#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string mdl, double prc) : model(mdl), price(prc) {}

    friend class InventoryManager;

    friend void comparePrice(const Car& car1, const Car& car2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        if (newPrice >= 0) {
            car.price = newPrice;
            cout << "Updated price of " << car.model << " to $" << newPrice << endl;
        } else {
            cout << "Invalid price!" << endl;
        }
    }

    void displayCar(const Car& car) {
        cout << "Car Model: " << car.model << ", Price: $" << car.price << endl;
    }
};


void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << "." << endl;
    } else if (car1.price < car2.price) {
        cout << car2.model << " is more expensive than " << car1.model << "." << endl;
    } else {
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
}

int main() {
    Car car1("Toyota Corolla", 20000);
    Car car2("Honda Civic", 22000);

    InventoryManager manager;

    manager.displayCar(car1);
    manager.displayCar(car2);
   
    manager.updatePrice(car1, 21000);

    comparePrice(car1, car2);

    return 0;
}
