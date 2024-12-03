
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Account class
class Account {
public:
    string accNum;
    string accPin;
    double balance;

    // Default constructor
    Account() : accNum(""), accPin(""), balance(0.0) {}

    // Parameterized constructor
    Account(string accNum, string accPin, double initialBalance)
        : accNum(accNum), accPin(accPin), balance(initialBalance) {}

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    // Function to check balance
    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

// ATM class
class ATM {
private:
    map<string, Account> accounts;

public:
    // Function to add an account
    void addAccount(string accNum, string accPin, double initialBalance) {
        accounts.emplace(accNum, Account(accNum, accPin, initialBalance));
    }

    // Function to authenticate a user
    Account* authenticate(string accNum, string accPin) {
        auto it = accounts.find(accNum);
        if (it != accounts.end() && it->second.accPin == accPin) {
            return &(it->second);
        } else {
            cout << "Authentication failed!" << endl;
            return nullptr;
        }
    }
};

// Main function
int main() {
    ATM atm;

    // Adding some test accounts
    atm.addAccount("12345", "1111", 1000.0);
    atm.addAccount("67890", "2222", 500.0);

    cout << "Welcome to the ATM!" << endl;

    // Authenticate user
    string accNum, accPin;
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter PIN: ";
    cin >> accPin;

    Account* userAccount = atm.authenticate(accNum, accPin);

    if (userAccount != nullptr) {
        int choice;
        do {
            cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    userAccount->checkBalance();
                    break;
                case 2: {
                    double depositAmount;
                    cout << "Enter deposit amount: ";
                    cin >> depositAmount;
                    userAccount->deposit(depositAmount);
                    break;
                }
                case 3: {
                    double withdrawAmount;
                    cout << "Enter withdrawal amount: ";
                    cin >> withdrawAmount;
                    userAccount->withdraw(withdrawAmount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option. Try again." << endl;
            }
        } while (choice != 4);
    }

    return 0;
}
