#include <iostream>
#include <string>
using namespace std;

// Base Class
class BankAccount{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal){
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else{
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount){
        if (amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else{
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    double getBalance(){
        return balance;
    }

    virtual void displayAccountInfo(){
        cout << "\nAccount Number   : " << accountNumber << endl;
        cout << "Account Holder   : " << accountHolderName << endl;
        cout << "Balance          : Rs. " << balance << endl;
    }

    virtual void calculateInterest(){
        cout << "Interest calculation is not available for this account.\n";
    }

    virtual ~BankAccount() {}
};


// Savings Account
class SavingsAccount : public BankAccount{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate): BankAccount(accNo, name, bal){
        interestRate = rate;
    }

    void calculateInterest() override{
        double interest = balance * interestRate / 100;

        cout << "Interest Rate    : " << interestRate << "%" << endl;
        cout << "Interest Amount  : Rs. " << interest << endl;
    }

    void displayAccountInfo() override{
        cout << "\n--- Savings Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Interest Rate    : " << interestRate << "%" << endl;
    }
};


// Checking Account
class CheckingAccount : public BankAccount{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit): BankAccount(accNo, name, bal){
        overdraftLimit = limit;
    }

    void withdraw(double amount) override{
        if (amount > 0 && amount <= balance + overdraftLimit){
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else{
            cout << "Withdrawal exceeds overdraft limit.\n";
        }
    }

    void checkOverdraft(){
        if (balance < 0){
            cout << "Overdraft used: Rs. " << -balance << endl;
        }
        else{
            cout << "No overdraft used.\n";
        }
    }

    void displayAccountInfo() override{
        cout << "\n--- Checking Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit  : Rs. " << overdraftLimit << endl;
    }
};


// Fixed Deposit Account
class FixedDepositAccount : public BankAccount{
private:
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int months): BankAccount(accNo, name, bal){
        term = months;
    }

    void calculateInterest() override{
        double interestRate = 7.0;
        double interest = balance * interestRate * term / (100 * 12);

        cout << "Term             : " << term << " months" << endl;
        cout << "Interest Rate    : " << interestRate << "%" << endl;
        cout << "Interest Amount  : Rs. " << interest << endl;
    }

    void displayAccountInfo() override{
        cout << "\n--- Fixed Deposit Account ---" << endl;
        BankAccount::displayAccountInfo();
        cout << "Term             : " << term << " months" << endl;
    }
};


// Main Function
int main(){
    SavingsAccount savings(101, "Vansh", 50000, 5.0);
    CheckingAccount checking(102, "Rahul", 20000, 10000);
    FixedDepositAccount fixedDeposit(103, "Aman", 100000, 12);

    cout << "====================================" << endl;
    cout << "       BANKING SYSTEM" << endl;
    cout << "====================================" << endl;

    savings.displayAccountInfo();
    savings.deposit(5000);
    savings.withdraw(2000);

    cout << "\nAfter Transactions:" << endl;
    savings.displayAccountInfo();

    cout << "\nSavings Interest:" << endl;
    savings.calculateInterest();


    checking.displayAccountInfo();
    checking.withdraw(25000);
    checking.checkOverdraft();

    cout << "\nAfter Transaction:" << endl;
    checking.displayAccountInfo();


    fixedDeposit.displayAccountInfo();

    cout << "\nFixed Deposit Interest:" << endl;
    fixedDeposit.calculateInterest();


    // Demonstrating Polymorphism
    cout << "\n====================================" << endl;
    cout << "       POLYMORPHISM DEMO" << endl;
    cout << "====================================" << endl;

    BankAccount *account;

    account = &savings;
    account->calculateInterest();

    account = &fixedDeposit;
    account->calculateInterest();

    return 0;
}