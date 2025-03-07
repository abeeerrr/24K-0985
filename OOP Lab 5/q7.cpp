#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    
public:
    Product(int ID, string n, int q) : id(ID), name(n), quantity(q) {}

    int getID() { return id; } 
    string getName() { return name; } 

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Inventory {
private:
    Product** products;
    int size;
    int capacity;

public:
    Inventory(int cap) : capacity(cap), size(0) {
        products = new Product*[capacity];
    }

    void addProduct(int id, string name, int quantity) {
        if (size < capacity) {
            products[size] = new Product(id, name, quantity);
            size++;
        } else {
            cout << "Inventory is full. Cannot add more products!" << endl;
        }
    }

    void sortByName() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (products[i]->getName() > products[j]->getName()) {
                    swap(products[i], products[j]);
                }
            }
        }
    }

    void searchByID(int id) {
        for (int i = 0; i < size; i++) {
            if (products[i]->getID() == id) {
                cout << "Product Found: ";
                products[i]->display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found!" << endl;
    }

    void displayInventory() {
        cout << "Inventory List:\n";
        for (int i = 0; i < size; i++) {
            products[i]->display();
        }
    }

    ~Inventory() {
        for (int i = 0; i < size; i++) {
            delete products[i];
        }
        delete[] products;
    }
};

int main() {
    Inventory warehouse(5);

    warehouse.addProduct(101, "ipad", 15);
    warehouse.addProduct(102, "table", 30);
    warehouse.addProduct(103, "strawberry", 50);
    warehouse.addProduct(104, "kitkat", 10);
    warehouse.addProduct(105, "balloon", 20);

    cout << "\nBefore Sorting:\n";
    warehouse.displayInventory();

    warehouse.sortByName();

    cout << "\nAfter Sorting:\n";
    warehouse.displayInventory();

    cout << "\nSearching for product with ID 103:\n";
    warehouse.searchByID(103);

    return 0;
}

