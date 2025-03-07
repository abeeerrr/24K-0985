#include <iostream>
#include <string>
using namespace std;

class Employee {
	private:
		string name;
		string designation;
		
		public:
		Employee(string n, string d) : name(n), designation(d) {} //initialization list
			
			void displayEmpDetails() {
				cout<<"the name of the employee is: "<<name<<endl;
				cout<<"the designation is: "<<designation<<endl;
			}
};

class Project{
	private: 
	string title;
	string deadline;
	Employee** employees;
	int numofemployees;
	
	public:
		Project(string t, string dl) : title(t), deadline(dl) {
			numofemployees=0;
			employees= new Employee* [5];
		}
			
			void addEmployee(Employee* e) {
				if (numofemployees < 5) {
					employees[numofemployees]=e;
					numofemployees++;
				} 
				else {
					cout<<"project is full! no more employees can be added!"<<endl;
				}
			
		}
		
		void displayProjdetails() {
			cout<<"title is: " << title<<endl;
			cout<<"deadline is: " << deadline << endl;
			cout<<"the employees are: "<<endl;
			
			  for(int i=0; i<numofemployees; i++) {
			  	employees[i]->displayEmpDetails();
			  }
		}
		
		~Project() {
		delete[] employees;
		}
		
		
};

int main() {
	
	Employee emp1("Abeer", "Architect");
	Employee emp2("Omer", "Computer Scientist");
	Employee emp3("Maaz", "Software Engineer");
	
	Project proj1("Jubail Building", "22-12-2025");
	Project proj2("Deepseek 2.0", "25-10-2025");
	Project proj3("Snake.io", "11-11-2025");
	
	proj1.addEmployee(&emp1);
	proj2.addEmployee(&emp2);
	proj3.addEmployee(&emp3);
	
	proj1.displayProjdetails();
	cout<<"\n"<<endl;
	proj2.displayProjdetails();
		cout<<"\n"<<endl;
	proj3.displayProjdetails();
		cout<<"\n"<<endl;
		
		
		return 0;
}