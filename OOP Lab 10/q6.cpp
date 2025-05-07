#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class InventoryItem {
public:
    int itemID;
    char itemName[20];

    InventoryItem(int id = 0, const char* name = "") {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }

    void writeToFile(const string& filename) {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }
        outFile.write(reinterpret_cast<char*>(this), sizeof(InventoryItem));
        outFile.close();
        cout << "Item written to file.\n";
    }

    void readFromFile(const string& filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Error: Could not open file for reading.\n";
            return;
        }
        inFile.read(reinterpret_cast<char*>(this), sizeof(InventoryItem));
        inFile.close();
        cout << "Item read from file.\n";
    }

    void display() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
    }
};

int main() {

    InventoryItem item1(1001, "Laptop");
    item1.writeToFile("inventory.dat");

    InventoryItem item2;
    item2.readFromFile("inventory.dat");

    cout << "\nLoaded Item Details:\n";
    item2.display();

    return 0;
}
