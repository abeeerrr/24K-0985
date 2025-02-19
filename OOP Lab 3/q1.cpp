#include <iostream>
#include <string>

using namespace std;

class Wallet {
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[100]; 
    int transactionCount;

       public:
    Wallet(string name, double initialBalance = 0.0) : ownerName(name), totalBalance(initialBalance), transactionCount(0) {
        transactionHistory[transactionCount++] = "Wallet created with balance: " + to_string(totalBalance);
    }

    void addMoney(double amount) {
        totalBalance += amount;
        transactionHistory[transactionCount++] = "Added: " + to_string(amount);
        cout << "Added " << amount << " to wallet. Balance: " << totalBalance << endl;
    }

    void spendMoney(double amount) {
        if (amount > totalBalance) {
            cout << "Insufficient funds!" << endl;
            transactionHistory[transactionCount++] = "Failed to spend: " + to_string(amount);
        } else {
            totalBalance -= amount;
            transactionHistory[transactionCount++] = "Spent: " + to_string(amount);
            cout << "Spent " << amount << ". Balance: " << totalBalance << endl;
        }
    }

    void displayHistory() const {
        cout << "History for " << ownerName << ":" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << transactionHistory[i] << endl;
        }
    }
};

int main() {
    Wallet saadWallet("Saad", 100.0);
    saadWallet.addMoney(50.0);
    saadWallet.spendMoney(30.0);
    saadWallet.spendMoney(150.0);
    saadWallet.displayHistory();
    return 0;
}


