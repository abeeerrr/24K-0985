#include <iostream>
#include <string>

using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) {
        securityLevel = level;
        cout << "AlarmSystem with security level '" << securityLevel << "' created.\n";
    }

    void displayAlarmDetails() const {
        cout << "Alarm Security Level: " << securityLevel << "\n";
    }

    ~AlarmSystem() {
        cout << "AlarmSystem with security level '" << securityLevel << "' destroyed.\n";
    }
};

class SmartHome {
private:
    string homeName;
    AlarmSystem alarm; 

public:
    SmartHome(string name, string securityLevel) : homeName(name), alarm(securityLevel) {
        cout << "SmartHome '" << homeName << "' created.\n";
    }

    void displayHomeDetails() const {
        cout << "Smart Home: " << homeName << "\n";
        alarm.displayAlarmDetails();
    }
    ~SmartHome() {
        cout << "SmartHome '" << homeName << "' destroyed.\n";
    }
};

int main() {
    
    SmartHome home1("Villa", "High");

    cout << "\n=== Smart Home Details ===\n";
    home1.displayHomeDetails();

    return 0;
}
