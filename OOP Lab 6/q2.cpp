#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}

    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int seatCount) : Vehicle(b, s), seats(seatCount) {}

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int seatCount, int bLife) 
        : Car(b, s, seatCount), batteryLife(bLife) {}

    void displayDetails() {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "enter electric car details:\n";
    cout << "Brand: ";
    cin >> ws;
    getline(cin, brand);
    cout << "Speed (km/h): ";
    cin >> speed;
    cout << "Seats: ";
    cin >> seats;
    cout << "Battery Life (hours): ";
    cin >> batteryLife;

    ElectricCar ecar(brand, speed, seats, batteryLife);

    cout << "\nElectric Car Details:\n";
    ecar.displayDetails();

    return 0;
}
