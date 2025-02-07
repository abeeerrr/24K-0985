#include <iostream>
#include <string>
using namespace std;

  struct Student {
    string name;
    int ID;
    float marks[3];
};


int main() {
    int n;
    cout << "take the number of students: ";
    cin >> n;
    cin.ignore();
    
    
    Student* records = new Student[n];

    for (int i=0; i<n; i++) {
    	
        cout << "take the details for student " << i + 1 << ":\n";
        
        cout << "Name: ";
        getline(cin, records[i].name);
        
        cout << "Roll No.: ";
        cin >> records[i].ID;
        
        for (int j=0; j<3; j++) {
            cout << "take the marks in subject "<<j+1<<" :";
            cin >> records[i].marks[j];
        }
        
        cin.ignore();
    }

    cout << "Avg Marks arre:"<<endl;
    for (int i=0; i<n; i++) {
        float avg = (records[i].marks[0] + records[i].marks[1] + records[i].marks[2]) / 3;
        cout << "Name: " << records[i].name << ", Avg Marks: " << avg << endl;
    }
    delete[] records;
    return 0;
}