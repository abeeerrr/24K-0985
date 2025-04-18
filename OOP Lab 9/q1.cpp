#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "InPatient Treatment Plan for " << name << " (ID: " << id << "):\n";
        cout << "- Admitted to hospital\n- Surgery/Observation\n- Medications & Care\n";
    }

    double calculateCost() const override {
        return 4800.0; 
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "OutPatient Treatment Plan for " << name << " (ID: " << id << "):\n";
        cout << "- Consultation\n- Lab Tests\n- Medications\n";
    }

    double calculateCost() const override {
        return 200.0;  
    }
};

int main() {
    const int SIZE = 2;
    Patient* patients[SIZE];

    patients[0] = new InPatient("Alice", "IP101");
    patients[1] = new OutPatient("Bob", "OP202");
    for (int i = 0; i < SIZE; ++i) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << "\n\n";
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; ++i) {
        delete patients[i];
    }

    return 0;
}
