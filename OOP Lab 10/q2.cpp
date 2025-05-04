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
