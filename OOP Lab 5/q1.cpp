#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* ownerName; 

public:
    
    Apartment(int aptId, string aptAddress, const char* owner) {
        id = aptId;
        address = aptAddress;


       int len=0;
        while (owner[len] != '\0') { 
            len++;
        }
        ownerName = new char[len+1];
        for (int i=0; i<len; i++) {
            ownerName[i]=owner[i]; 
        }
        ownerName[len] = '\0'; 
    }

    Apartment(const Apartment& other) {
        id=other.id;
        address=other.address;
        ownerName=other.ownerName;
    }

    void display() const {
        cout << "Apartment ID: " << id << "\n";
        cout << "Address: " << address << "\n";
        cout << "Owner: " << ownerName << "\n";
    }

    ~Apartment() {
        delete[] ownerName;
    }
};

int main() {

    Apartment apt1(2006, "Hayat Tayyaba", "abeer fatima");

    
    cout << "Original Apartment\n";
    apt1.display();

    Apartment apt2=apt1; 

 
    cout << "Copied Apartment\n";
    apt2.display();

    return 0;
}



