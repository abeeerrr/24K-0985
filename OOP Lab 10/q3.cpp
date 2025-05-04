#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class VehicleDataProcessor {
private:
    string filename;

public:
    VehicleDataProcessor(const string& file) : filename(file) {}

    void processFile() {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {

            if (line.empty() || line[0] == '#')
                continue;

            parseLine(line);
        }

        inFile.close();
    }

private:
    void parseLine(const string& line) {
        istringstream ss(line);
        string type, id, name, yearStr, extraData, certification;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearStr, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');
       
        int year = stoi(yearStr); 

        cout << "Type: " << type << ", ID: " << id
             << ", Name: " << name << ", Year: " << year
             << ", ExtraData: " << extraData
             << ", Certification: " << certification << endl;
    }
};

int main() {
    VehicleDataProcessor processor("abeer.txt"); 
    processor.processFile();
    return 0;
}
