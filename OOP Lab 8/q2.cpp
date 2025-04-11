#include <iostream>

using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:

    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;

    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " into Account " << acc.accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(Account& acc, double amount) {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrawn $" << amount << " from Account " << acc.accountNumber << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed: Insufficient balance or invalid amount!" << endl;
    }
}

int main() {
    Account acc1(1001, 500.0);
    Account acc2(1002, 300.0);
    
    Manager manager;

    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    manager.deposit(acc1, 200.0);
    manager.withdraw(acc2, 50.0);
    
    transferFunds(acc1, acc2, 100.0);

    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    return 0;
}
