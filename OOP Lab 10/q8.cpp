#include <iostream>
#include <fstream>

using namespace std;

int main() {
   
    ofstream configOut("config.txt");
    configOut << "AAAAABBBBBCCCCC";
    configOut.close();

    fstream configFile("config.txt", ios::in | ios::out);
    if (!configFile) {
        cerr << "Failed to open config.txt.\n";
        return 1;
    }

    configFile.seekp(5);
    configFile << "XXXXX";
    configFile.close();


    ifstream verifyFile("config.txt");
    string result;
    getline(verifyFile, result);
    cout << "Updated file content: " << result << endl;
    verifyFile.close();

    return 0;
}

