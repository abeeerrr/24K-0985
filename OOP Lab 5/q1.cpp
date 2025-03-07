#include <iostream>
#include <string>
using namespace std;

class Apartment {
	
	private:
		int ID;
		string address;
		string *ownerName;
		
		public: 
		
		Apartment (int id, string add, string name) {
			ID=id;
			address=add;
			ownerName= new string(name);
		}
		
		Apartment(const Apartment &other) {
			ID=other.ID;
			address=other.address;
			ownerName=other.ownerName;
		}
		
		void display() {
			cout<<"the id is: "<<ID<<endl;
			cout<<"the address is "<<address<<endl;
			cout<<"the owner name is: "<<*ownerName<<endl;
		}
		
		~Apartment() {
			delete ownerName;
		}
};


int main() {
	Apartment APT(2006, "Hayat Tayyabah", "Abeer Fatima"); 
	APT.display(); //original apartment
	
	Apartment apt=APT;
	apt.display(); //copied apartment
	
	return 0;
	
}