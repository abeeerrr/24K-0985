#include <iostream>
#include <string>

using namespace std;

class WeatherSensor {

public:

    virtual void readData() = 0;
    virtual void displayreport() const = 0;

    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {

private: 
    float temperature;

public:

    Thermometer(float t = 0.0f) : temperature(t) {}

    void readData() override {
        temperature = 34.6f;
    }

    void displayreport() const override {
        cout << "Temperature: " << temperature << " °C" << endl;
    }
};

class Barometer : public WeatherSensor {

private:
    float pressure;

public:

    Barometer(float p = 0.0f) : pressure(p) {}

    void readData() override {
        pressure = 14.7f;
    }

    void displayreport() const override {
        cout << "Pressure: " << pressure << " psi" << endl;
    }
};

int main() {

    const int sensorCount = 2; // pressure and barometer

    // stack allocation
    Thermometer t;
    Barometer b;

    // correct array declaration
    WeatherSensor* sensors[sensorCount] = { &t, &b };

    for (int i = 0; i < sensorCount; i++) {
        sensors[i]->readData();
        sensors[i]->displayreport();
    }

    return 0;
}

