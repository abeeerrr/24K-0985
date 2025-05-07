#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outfile("large_log.txt");
    outfile << "This is the first part of the log.\n";
    outfile << "This is the second part of the log.\n";
    outfile << "And the third part.\n";
    outfile.close();

    ifstream infile("large_log.txt");

    if (!infile) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    char buffer[11];
    infile.read(buffer, 10);
    buffer[infile.gcount()] = '\0';
    cout << "First 10 characters: " << buffer << endl;
    cout << "Position after first read: " << infile.tellg() << endl;

    infile.read(buffer, 10);
    buffer[infile.gcount()] = '\0';
    cout << "Next 10 characters: " << buffer << endl;
    cout << "Position after second read: " << infile.tellg() << endl;

    infile.close();
    return 0;
}
