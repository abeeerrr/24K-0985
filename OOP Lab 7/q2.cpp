#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual double applyDiscount() const {
        return price;
    }

    virtual double calculateTotalPrice(int quantity) const {
        return applyDiscount() * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "\nProduct ID: " << productID
             << "\nProduct Name: " << productName
             << "\nPrice: $" << price
             << "\nStock Quantity: " << stockQuantity << endl;
    }

    double operator+(int quantity) const {
        return calculateTotalPrice(quantity);
    }

    friend ostream& operator<<(ostream& os, const Product& product) {
        product.displayProductInfo();
        return os;
    }

    virtual ~Product() {}
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string b)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Brand: " << brand
             << "\nWarranty Period: " << warrantyPeriod << " years" << endl;
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fabric)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}

    double applyDiscount() const override {
        // Applying 20% seasonal discount
        return price * 0.8;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size
             << "\nColor: " << color
             << "\nFabric Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string expDate, int cal)
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    double calculateTotalPrice(int quantity) const override {
        double total = price * quantity;
        if (quantity > 10) { // Apply bulk discount if quantity is greater than 10
            total *= 0.9;
        }
        return total;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate
             << "\nCalories: " << calories << " kcal" << endl;
    }
};

class Book : public Product {
private:
    string author;
    string genre;

public:
    Book(int id, string name, double p, int stock, string auth, string gen)
        : Product(id, name, p, stock), author(auth), genre(gen) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author
             << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics laptop(201, "Laptop", 1000, 50, 2, "Dell");
    Clothing shirt(202, "T-Shirt", 20, 100, "M", "Blue", "Cotton");
    FoodItem apple(203, "Apple", 1.5, 200, "2025-12-31", 52);
    Book book(204, "C++ Programming", 35, 30, "Bjarne Stroustrup", "Educational");

    cout << laptop;
    cout << shirt;
    cout << apple;
    cout << book;

    cout << "\nPrice of 15 apples: $" << apple + 15 << endl;
    cout << "\nPrice of 5 shirts with discount: $" << shirt + 5 << endl;

    return 0;
}
