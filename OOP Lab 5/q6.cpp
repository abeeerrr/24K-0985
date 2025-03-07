#include <iostream>
#include <string>
using namespace std;

class Level {
	private:
		int levelnum;
		string levelname;
		int difficulty; //out of three
		
	public:
	   Level(int lvlnum, string name, int diff) : levelnum(lvlnum), levelname(name), difficulty(diff) {}
		
		void displaydetails() {
			cout<<"the level num is: "<<levelnum<<endl;
			cout<<"the level name is: "<<levelname<<endl;
			cout<<"the difficulty is: "<<difficulty<<endl;
		}
		
};

class VideoGame{
	private:
		string title;
		string genre;
		int numoflevels;
		Level** levels;
		
	public:
		VideoGame(string t, string g, int num) : title(t), genre(g), numoflevels(num)  {
			levels=new Level*[numoflevels];
			
		}
		
	void addLevel(int index, string name, int difficulty) {
        if (index >= 0 && index < numoflevels) {
            levels[index] = new Level(index + 1, name, difficulty); // dma
        }
    }

    void displayGameDetails() {
        cout << "Game: " << title<<endl;
		cout << "Genre: " << genre<<endl;
        cout << "Levels: "<<endl;
        for (int i=0; i < numoflevels; i++) {
            levels[i]->displaydetails();
        }
    }

    ~VideoGame() {
        for (int i = 0; i < numoflevels; i++) {
            delete levels[i]; // delete each level
        }
        delete[] levels; // delete the array
    }
};

int main() {
    VideoGame game("Order Up", "Cooking", 1000);

    game.addLevel(0, "Frying", 2);
    game.addLevel(1, "Baking", 4);
    game.addLevel(2, "Boiling", 5);

    game.displayGameDetails();

    return 0;
}