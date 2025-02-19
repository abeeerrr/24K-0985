#include <iostream>
#include <vector>

using namespace std;

class Library {
private:
    struct Book {
        string title;
        int availableCopies;
        int borrowedCopies;
    };

    vector<Book> bookList;

    int findBookIndex(const string &bookName) {
        for (size_t i = 0; i < bookList.size(); i++) {
            if (bookList[i].title == bookName) {
                return i;
            }
        }
        return -1; 
    }

public:
    void addBook(string bookName, int quantity) {
        int index = findBookIndex(bookName);
        if (index != -1) {
            bookList[index].availableCopies += quantity;
        } else {
            bookList.push_back({bookName, quantity, 0});
        }
        cout << quantity << " copies of '" << bookName << "' added to the library.\n";
    }

    void lendBook(string bookName) {
        int index = findBookIndex(bookName);
        if (index != -1 && bookList[index].availableCopies > 0) {
            bookList[index].availableCopies--;
            bookList[index].borrowedCopies++;
            cout << "Book '" << bookName << "' has been borrowed.\n";
        } else {
            cout << "Sorry, '" << bookName << "' is currently unavailable.\n";
        }
    }

    void returnBook(string bookName) {
        int index = findBookIndex(bookName);
        if (index != -1 && bookList[index].borrowedCopies > 0) {
            bookList[index].borrowedCopies--;
            bookList[index].availableCopies++;
            cout << "Book '" << bookName << "' has been returned.\n";
        } else {
            cout << "Error: '" << bookName << "' was not borrowed.\n";
        }
    }

    void displayBooks() {
        cout << "\nLibrary Inventory:\n";
        for (const auto &book : bookList) {
            cout << book.title << " - Available: " << book.availableCopies
                 << ", Borrowed: " << book.borrowedCopies << endl;
        }
    }
};

int main() {
    Library lib;

    lib.addBook("C++ Programming", 3);
    lib.addBook("MVC", 2);

    lib.lendBook("C++ Programming");
    lib.lendBook("MVC");

    lib.displayBooks();

    lib.returnBook("C++ Programming");

    lib.displayBooks();

    return 0;
}
