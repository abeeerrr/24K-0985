#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;  
    int numScores;

public:
    Student(int studentId, string studentName, int* studentScores, int scoreCount) {
        id = studentId;
        name = studentName;
        numScores = scoreCount;

        scores = new int[numScores];
        for (int i=0; i<numScores; i++) {
            scores[i] = studentScores[i];  
        }
    }

    Student(const Student& other) {
        id = other.id;
        name = other.name;
        numScores = other.numScores;

        scores = new int[numScores];
        for (int i=0; i<numScores; i++) {
            scores[i] = other.scores[i];
        }
    }

    void display() const {
        cout << "Student ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Scores: ";
        for (int i=0; i<numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << "\n";
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int scores1[] = {66, 68, 70};
    Student student1(101, "abeer", scores1, 3);

    cout << "Original Student\n";
    student1.display();

    Student student2 = student1;

    cout << "Copied Student\n";
    student2.display();

    return 0;
}
