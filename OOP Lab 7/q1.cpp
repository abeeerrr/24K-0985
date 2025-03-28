#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc = "")
        : deviceID(id), deviceName(name), status(false), location(loc) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " is now ON." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " is now OFF." << endl;
    }

    virtual void getStatus() const {
        cout << deviceName << " status: " << (status ? "ON" : "OFF") << endl;
    }

    virtual void displayInfo() const {
        cout << "\nDevice ID: " << deviceID 
             << "\nName: " << deviceName 
             << "\nLocation: " << location 
             << "\nStatus: " << (status ? "ON" : "OFF") << endl;
    }

    virtual ~Device() {}
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, int brightness, string color, string loc = "")
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel 
             << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    int temperature;
    string mode;
    int targetTemperature;

public:
    Thermostat(int id, string name, int temp, string m, int target, string loc = "")
        : Device(id, name, loc), temperature(temp), mode(m), targetTemperature(target) {}

    void getStatus() const override {
        cout << deviceName << " Temperature: " << temperature 
             << "°C, Mode: " << mode 
             << ", Target: " << targetTemperature << "°C" << endl;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string res, bool nightVision, string loc = "")
        : Device(id, name, loc), resolution(res), recordingStatus(false), nightVisionEnabled(nightVision) {}

    void turnOn() override {
        recordingStatus = true;
        status = true;
        cout << deviceName << " is now recording." << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Resolution: " << resolution 
             << "\nRecording Status: " << (recordingStatus ? "Recording" : "Not Recording") 
             << "\nNight Vision Enabled: " << (nightVisionEnabled ? "Yes" : "No") << endl;
    }
};

class SmartPlug : public Device {
private:
    int powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, int power, int timer, string loc = "")
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        status = false;
        cout << deviceName << " turned off. Power consumption logged: " 
             << powerConsumption << "W." << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption 
             << "W\nTimer Setting: " << timerSetting << " minutes" << endl;
    }
};

int main() {
    Light light(101, "Living Room Light", 75, "Warm White", "Living Room");
    Thermostat thermostat(102, "Smart Thermostat", 22, "Heating", 25, "Bedroom");
    SecurityCamera camera(103, "Outdoor Camera", "1080p", true, "Front Door");
    SmartPlug plug(104, "Coffee Maker Plug", 1000, 30, "Kitchen");


    light.turnOn();
    light.displayInfo();
    
    thermostat.getStatus();
    
    camera.turnOn();
    camera.displayInfo();
    
    plug.turnOff();
    plug.displayInfo();
    
    return 0;
}
