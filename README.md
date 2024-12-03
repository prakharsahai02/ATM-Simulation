# ATM-Simulation
1. Project Overview
The ATM simulation will allow users to perform basic banking operations such as:

Authenticate using a PIN.
Check account balance.
Deposit money.
Withdraw money.
Exit the system.
2. Classes and Methods
Class: ATM
Attributes:
atm_balance (total cash available in the ATM)
accounts (a dictionary of account numbers and corresponding Account objects)
Methods:
authenticate(account_number, pin): Validates account number and PIN.
perform_transaction(account_number): Provides options like balance check, deposit, withdrawal, or exit.
Class: Account
Attributes:
account_number
pin
balance
Methods:
check_balance(): Returns the current balance.
deposit(amount): Adds money to the account.
withdraw(amount): Deducts money from the account if sufficient funds are available.
