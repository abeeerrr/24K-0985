#include <iostream>
#include <string>
using namespace std;

struct book{
    string title;
    string author;
    int year;
};

int main(){
    int n;
    cout << "take the number of book you want to enter: ";
    cin >> numofbooks;
    cin.ignore();
    book* books = new book[numofbooks];
    
    for (int i = 0; i < numofbooks ; i++)
    {
        cout << "take the book "<<i+1<<" title: ";
        getline(cin,books[i].title);
        cout << "take the book "<<i+1<<" author: ";
        getline(cin,books[i].author);
        cout << "take the book "<<i+1<<" year: ";
        cin>>books[i].year;
        cin.ignore();
    }
    
    int y;
    cout<<"take a year to see books published after it: ";
    cin>>year;
    cout << "\nBooks published after " << y << ":"<<endl;
    bool found=false;
    for (int i = 0; i < n; i++)
    
	{
        if(books[i].year>y){
            found = true;
            cout << "Book "<<i+1<<" :\n"<<books[i].title<<"\n"<<books[i].author<<"\n"<<books[i].year<<endl;
        }
    }
    if (!found) {
        cout << "No books found published after " << y << ".\n";
    }
    
    delete[] books;
    return 0;
}