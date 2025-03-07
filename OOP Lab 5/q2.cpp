#include <iostream>
#include <string>
using namespace std;

class Student {
	
	private: 
	int ID;
	string name;
	int *scores;
	int numofscores;
	
	
	public:
		Student(int id, string n, int *s, int num) {
			ID=id;
			name=n;
			numofscores=num;
			scores= new int[numofscores]; //dma
			
			
			
			for(int i=0;i<numofscores;i++) {
				scores[i]=s[i];
			}
		}
		
		Student(const Student &other) {
			ID=other.ID;
			name=other.name;
			numofscores=other.numofscores;
			scores=new int[numofscores];
			
			
			for(int i=0; i<numofscores; i++) {
				scores[i]=other.scores[i];
			}
		}
		
		void display() {
			cout<<"the student's id is: "<<ID<<endl;
			cout<<"the students name is: "<<name<<endl;
			cout<<"the number of scores is: "<<numofscores<<endl;
			cout<<"the scores are: ";
			for (int i = 0; i < numofscores; i++) {
			 cout<<" "<<scores[i];
		}
	}
		
		
		~Student() {
			delete[] scores;
		}
	
};

int main() {
	
	int SCORES[]={99,98,96,97,100};
	
	cout<<"the original record: \n"<<endl;
	Student std(2006, "Abeer Fatima", SCORES,5);
	std.display();
	
	cout<<"\nthe copied record: \n"<<endl;
	Student std2=std;
	std2.display(); 
	
	return 0;
	
	

}