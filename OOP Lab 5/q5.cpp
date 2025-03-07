#include <iostream>
#include <string>
using namespace std;

class Doctor {
	private:
		string name;
		string specialization;
		string experience;
		
	public:
		Doctor(string n, string spec, string exp) : name(n), specialization(spec), experience(exp) {
			
		}
		
		void display() {
			cout<<"the name of the doctor is: "<<name<<endl;
			cout<<"the specialization is: " << specialization<<endl;
			cout<<"the experience is: "<< experience<<endl;
			
		}
};

class Hospital {
	private:
		string hospName;
		Doctor** doctors; 
		int numofdoctors;
		
		public:
			
			Hospital(string name, int numofdr) : hospName(name), numofdoctors(numofdr) {
				numofdoctors=0;
				doctors= new Doctor*[10];
			}
			void addDoctor(Doctor* dr){
				if (numofdoctors<10) {
					doctors[numofdoctors]=dr;
					numofdoctors++;
				}
				else {
					cout<<"the capacity is full! no more doctors!"<<endl;
				}
				
				
			}
			
			void displayHospdetails() {
				cout<<"the hospital is: "<<hospName<<endl;
				cout<<"the number of doctors is: "<<numofdoctors<<endl;
				cout<<"the doctors working here are: "<<endl;
				
				for(int i=0; i<numofdoctors; i++) {
					doctors[i]->display();
				}
			}
			
			~Hospital() {
				delete[] doctors;
			}
		
	
};


int main() {
    Doctor doc1("Dr. Abeer", "Cardiology", "10 years");
    Doctor doc2("Dr. Omer", "Neurology", "15 years");
    Doctor doc3("Dr. Maaz", "Dermatology", "11 years");	
    
    Hospital hosp1("Almana Hospital", 22);
    Hospital hosp2("Mouwasat Hospital", 50);
    Hospital hosp3("King Fahd Hospital", 100);
    
    hosp1.addDoctor(&doc1);
    hosp2.addDoctor(&doc2);
    hosp3.addDoctor(&doc3);
    hosp3.addDoctor(&doc2); //Dr Omer works at King Fahd and Mouwasat Hosp
    
    hosp1.displayHospdetails();
    cout<<"\n"<<endl;
    hosp2.displayHospdetails();
    cout<<"\n"<<endl;
    hosp3.displayHospdetails();
    cout<<"\n"<<endl;
    
    return 0;
}