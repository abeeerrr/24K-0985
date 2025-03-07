#include <iostream>

using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool s) : deviceID(id), status(s) {}

    virtual void displayDetails() { 
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {  
protected:
    float screenSize;

public:
    SmartPhone(int id, bool s, float size) : Device(id, s), screenSize(size) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {  
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool s, bool hrm) : Device(id, s), heartRateMonitor(hrm) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool s, float size, bool hrm, int steps)
        : Device(id, s), SmartPhone(id, s, size), SmartWatch(id, s, hrm), stepCounter(steps) {}

    void displayDetails() override {
        Device::displayDetails();  
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;

    cout << "Enter Smart Wearable details:\n";
    cout << "Device ID: ";
    cin >> deviceID;
    cout << "Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Step Counter: ";
    cin >> stepCounter;

    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);

    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}

