#include <iostream>
#include <string>

using namespace std;

     struct inventory {
    int productID;
    string name;
    int quantity;
    float price;
};

        int main() {
    int n;
    cout << "take the number of products: ";
    cin >> n;
    
    
    inventory *products = new inventory[n];

    for (int i=0; i<n; i++) {
        cout<<"take the products id:";
        cin>>products[i].productID;        
        cin.ignore();
        
        cout << "take the the product's name: ";
        getline(cin, products[i].name);
        
        cout << "take the quantity of product required: ";
        cin >> products[i].quantity;
        
        cout << "take the price: ";
        cin >> products[i].price;
    }

    float sum = 0;
    for (int i=0; i<n; i++) {
        cout << "the cost of " << products[i].name << ": " << products[i].quantity * products[i].price << endl;
        sum = sum + products[i].quantity * products[i].price;
    }
    cout<<"the total value is: "<<sum; 
    delete[] products;
    return 0;
}