#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class FileReader {
private:
    string filename;
    ifstream file;

public:
    FileReader(const string& fname) : filename(fname) {}

    void readAndParseFile() {
        file.open(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open the file \"" << filename << "\"." << endl;
            return;
        }

        string line;
        cout << "Reading and parsing from file: " << filename << "\n\n";

        while (getline(file, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            }

            istringstream ss(line);
            string type, id, name, year, extraData, certification;

            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, extraData, ',');
            getline(ss, certification, ',');

            cout << "Type: " << type << "\n";
            cout << "ID: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Year: " << year << "\n";
            cout << "ExtraData: " << extraData << "\n";
            cout << "Certification: " << certification << "\n";

            if (type == "HybridTruck") {
                size_t colonPos = extraData.find(':');
                size_t pipePos = extraData.find('|');

                if (colonPos != string::npos && pipePos != string::npos) {
                    
                    string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
                    int cargoValue = stoi(cargoStr);

                  
                    size_t batteryPos = extraData.find("Battery:");
                    if (batteryPos != string::npos) {
                        string batteryStr = extraData.substr(batteryPos + 8);
                        int batteryValue = stoi(batteryStr);

                        cout << "Parsed HybridTruck Data:\n";
                        cout << "  Cargo: " << cargoValue << "\n";
                        cout << "  Battery: " << batteryValue << "\n";
                    } else {
                        cout << "  Error: 'Battery:' keyword not found.\n";
                    }
                } else {
                    cout << "  Error: Improper ExtraData format for HybridTruck.\n";
                }
            }
            else if (type == "Car" || type == "Truck" || type == "Bike") {
            }
            else {
                cout << "  Error: Unknown vehicle type '" << type << "'\n";
            }

            cout << "-----------------------------\n";
        }

        file.close();
    }
};

int main() {
    FileReader reader("abeer.txt");
    reader.readAndParseFile();
    return 0;
}
