#include <iostream>
#include <string>
using namespace std;

const int MAX_PATIENTS = 100;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() const {
        cout << "\nName: " << name
             << "\nAge: " << age
             << "\nContact Number: " << contactNumber
             << "\nAddress: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddress = "") {
        contactNumber = newContact;
        if (!newAddress.empty()) {
            address = newAddress;
        }
        cout << "Information updated successfully." << endl;
    }

    virtual ~Person() {}
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, int id, string history, string doctor, string addr = "")
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID
             << "\nMedical History: " << medicalHistory
             << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    string patientsList[MAX_PATIENTS];
    int patientCount;

public:
    Doctor(string n, int a, string contact, string spec, double fee, string addr = "")
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientCount(0) {}

    void addPatient(string patientName) {
        if (patientCount < MAX_PATIENTS) {
            patientsList[patientCount++] = patientName;
            cout << "Patient " << patientName << " added to the doctor's list." << endl;
        } else {
            cout << "Cannot add more patients. Maximum limit reached!" << endl;
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization
             << "\nConsultation Fee: $" << consultationFee
             << "\nPatients List: ";
        
        if (patientCount == 0) {
            cout << "No patients assigned yet." << endl;
        } else {
            for (int i = 0; i < patientCount; i++) {
                cout << patientsList[i] << (i < patientCount - 1 ? ", " : "");
            }
            cout << endl;
        }
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift, string addr = "")
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard
             << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string dept, double sal, string addr = "")
        : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress = "") override {
        Person::updateInfo(newContact, newAddress);
        cout << "Administrator information updated successfully." << endl;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nSalary: $" << salary << endl;
    }
};

int main() {
    Patient patient("Abeer", 22, "123-456-7890", 1001, "Diabetes", "Dr. Talha");
    Doctor doctor("Dr. Talha", 40, "456-789-0123", "Cardiology", 1500);
    Nurse nurse("Sana", 30, "789-012-3456", "Ward A", "Day Shift");
    Administrator admin("Ali", 35, "234-567-8901", "HR", 5000);

    patient.displayInfo();
    doctor.displayInfo();
    nurse.displayInfo();
    admin.displayInfo();

 
    doctor.addPatient("Abeer");
    doctor.displayInfo();

    admin.updateInfo("999-888-7777", "New Street, City");

    return 0;
}

