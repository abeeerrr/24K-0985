#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader {
private:
    string filename;
    ifstream file;

public:
  
    FileReader(const string& fname) : filename(fname) {}

    void readFile() {
        file.open(filename);

       
        if (!file.is_open()) {
            cerr << "Error: Could not open the file \"" << filename << "\"." << endl;
            return;
        }

        string line;
        cout << "Reading from file: " << filename << "\n\n";

        while (getline(file, line)) {
         
            if (line.empty() || line[0] == '#') {
                continue;
            }
            cout << line << endl;
        }

        file.close();
    }
};

int main() {
   
    FileReader reader("abeer.txt");


    reader.readFile();

    return 0;
}
