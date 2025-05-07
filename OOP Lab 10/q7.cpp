#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");

    if (!outFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    outFile << "Sensor 1: 25.5 C\n";
    cout << "Put pointer after line 1: " << outFile.tellp() << endl;

    outFile << "Sensor 2: 98.1 %RH\n";
    cout << "Put pointer after line 2: " << outFile.tellp() << endl;

    outFile.close();
    return 0;
}

