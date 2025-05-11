#include <iostream>
#include <exception>

using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const throw() {
        return "A database error occurred.";
    }
};


class ConnectionFailedException : public DatabaseException {
   
};

class QueryTimeoutException : public DatabaseException {
   
};

template <typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        } else {
            cout << "Connected to " << dbName << " successfully.\n";
        }
    }
};

int main() {
    DatabaseConnector<string> db;

    try {
        cout << "Attempting to connect to invalid_db...\n";
        db.connect("invalid_db");
    } catch (ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to connect to slow_db...\n";
        db.connect("slow_db");
    } catch (DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
