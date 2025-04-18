#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails() const override {
        cout << "Appetizer: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation steps: Mix fresh ingredients, serve cold or light warm.\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails() const override {
        cout << "Main Course: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation steps: Cook meat or vegetables, serve with sides.\n";
    }
};

int main() {
    const int SIZE = 2;
    MenuItem* menu[SIZE];
    menu[0] = new Appetizer("Spring Rolls", 5.99);
    menu[1] = new MainCourse("Grilled Chicken", 12.49);


    for (int i = 0; i < SIZE; ++i) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << endl;
    }

    for (int i = 0; i < SIZE; ++i) {
        delete menu[i];
    }

    return 0;
}
