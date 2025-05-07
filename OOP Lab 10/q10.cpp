#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("data_records.txt");
    outfile << "Record 1\n";
    outfile << "Record 2\n";
    outfile << "Record 3\n";
    outfile << "Record 4\n";
    outfile.close();

    ifstream infile("data_records.txt");

    if (!infile) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    string line;
    
    getline(infile, line); // Skip Record 1
    getline(infile, line); // Skip Record 2

    // Now read the third
    getline(infile, line); // Read Record 3

    cout << "Third record: " << line << endl;

    infile.close();
    return 0;
}


