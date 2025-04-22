#include <iostream>
#include <string>

using namespace std;

class Course {

     public:
    string courseCode;
    int credits;

 
    Course(const string& code, int cr) : courseCode(code), credits(cr) {}

    virtual void calculateGrade()=0;


    virtual void displayInfo() const=0; //since coursecount is const

    virtual ~Course () {} //destructor since we used dma

};

class LectureCourse : public Course {
    private:
float midterm;
float finalExam;

public:

LectureCourse(const string& code, int cr, float mt, float fe) : Course (code, cr), midterm(mt), finalExam(fe) {}

void calculateGrade () override {

float finalGrade= 0.3f*midterm + 0.7f*finalExam;

 cout<<"the final grade of your lectures is: " << finalGrade << endl;

}

void displayInfo () const override {
 
 cout<< "Lecture course: " <<courseCode<<endl;
 cout<<"Number of credits: "<< credits<<endl;

}


};

class LabCourse : public Course {
    private:

    float labWork;
    float labExam;

    public:

    LabCourse(const string& code, int cr, float lw, float le) : Course (code, cr), labWork(lw), labExam(le) {} 

    void calculateGrade () override { 
        float finalGrade = 0.3f*labWork + 0.7f*labExam;

        cout<<"the final grade of your lab is: "<<finalGrade<<endl;
    }

    void displayInfo()const override {

        cout<<"Lab course: "<< courseCode <<endl;
        cout<<"Number of credits:"<<credits<<endl;
    }

};

int main() {

const int courseCount=2; //lecture and lab course
Course* courses[courseCount]; //declaring an array to store all courses info

//manually adding info into each course

courses[0]= new LectureCourse("MT1003", 3, 80.45f, 75.6f); //calling constructors
courses[1]= new LabCourse("CS007", 1, 60.5f, 90.5f);

//displaying array
for(int i=0; i < courseCount; i++) {
    courses[i]->displayInfo();
    courses[i]->calculateGrade();
}

//freeing memory

for (int i=0; i < courseCount; i++) {
    delete courses[i];
}


return 0;


}


/* if u dont wanna use new in main, use pointer stack before displaying array as:

Courses* course(courseCount) = {&lc, &lab}; 

that's it




*/