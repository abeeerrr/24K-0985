#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayDetails() {
        cout << "Name: "<< name <<endl;
        cout << "Age: "<< age <<endl;
    }
};

class Teacher : public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}

    void displayDetails(){
        Person::displayDetails();
        cout << "Subject: " <<subject<< endl;
    }
};

class Researcher : public Teacher {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string sub, string rArea) 
        : Teacher(n, a, sub), researchArea(rArea) {}

    void displayDetails(){
        Teacher::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string rArea, int pubs) 
        : Researcher(n, a, sub, rArea), publications(pubs) {}

    void displayDetails(){
        Researcher::displayDetails();
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "enter professor's details:\n";
    cout << "name: ";
    cin >> ws;
    cin>> name;
    cout << "Age: ";
    cin >> age;
    cout << "Subject: ";
    cin >> ws;
    getline(cin, subject);
    cout << "Research Area: ";
    cin >> ws;
    getline(cin, researchArea);
    cout << "Number of Publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);

    cout << "\nProfessor Details:\n";
    prof.displayDetails();

    return 0;
}
