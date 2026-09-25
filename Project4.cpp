#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
private:
string accountNumber;
string accountHolderName;
double balance;

public:
BankAccount(string accNo, string name, double bal)
{
accountNumber = accNo;
accountHolderName = name;
balance = bal;
}

virtual ~BankAccount() {}

virtual void deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;
    cout << "Amount deposited successfully.\n";
}

virtual void withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;
    cout << "Amount withdrawn successfully.\n";
}

double getBalance() const
{
    return balance;
}

protected:
void setBalance(double newBalance)
{
balance = newBalance;
}

public:
string getAccountNumber() const
{
return accountNumber;
}

string getAccountHolderName() const
{
    return accountHolderName;
}

virtual void calculateInterest()
{
    cout << "Interest calculation is not available for this account.\n";
}

virtual void checkOverdraft()
{
    cout << "Overdraft facility is not available for this account.\n";
}

virtual void displayAccountInfo() const
{
    cout << "\n-----------------------------\n";
    cout << "Account Number : " << accountNumber << endl;
    cout << "Account Holder : " << accountHolderName << endl;
    cout << "Balance        : Rs. " << balance << endl;
    cout << "-----------------------------\n";
}

};

class SavingsAccount : public BankAccount
{
private:
double interestRate;

public:
SavingsAccount(string accNo, string name, double bal,
double rate)
: BankAccount(accNo, name, bal)
{
interestRate = rate;
}

void calculateInterest() override
{
    double interest = getBalance() * interestRate / 100;

    cout << "\nSavings Account Interest\n";
    cout << "Interest Rate : " << interestRate << "%" << endl;
    cout << "Interest      : Rs. " << interest << endl;
}

void displayAccountInfo() const override
{
    cout << "\n===== SAVINGS ACCOUNT =====\n";
    BankAccount::displayAccountInfo();
    cout << "Interest Rate  : " << interestRate << "%" << endl;
}

};

class CheckingAccount : public BankAccount
{
private:
double overdraftLimit;

public:
CheckingAccount(string accNo, string name, double bal,
double limit)
: BankAccount(accNo, name, bal)
{
overdraftLimit = limit;
}

void withdraw(double amount) override
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount.\n";
        return;
    }

    if (amount > getBalance() + overdraftLimit)
    {
        cout << "Withdrawal exceeds overdraft limit.\n";
        return;
    }

    setBalance(getBalance() - amount);

    cout << "Amount withdrawn successfully.\n";

    if (getBalance() < 0)
    {
        cout << "Warning: You are using your overdraft facility.\n";
    }
}

void checkOverdraft() override
{
    cout << "\nChecking Account Overdraft\n";
    cout << "Overdraft Limit : Rs. " << overdraftLimit << endl;

    if (getBalance() < 0)
    {
        cout << "Overdraft Used  : Rs. "
             << -getBalance() << endl;
    }
    else
    {
        cout << "Overdraft Used  : Rs. 0\n";
    }
}

void displayAccountInfo() const override
{
    cout << "\n===== CHECKING ACCOUNT =====\n";
    BankAccount::displayAccountInfo();
    cout << "Overdraft Limit : Rs. "
         << overdraftLimit << endl;
}

};

class FixedDepositAccount : public BankAccount
{
private:
int term;
double interestRate;

public:
FixedDepositAccount(string accNo, string name, double bal,
int months, double rate)
: BankAccount(accNo, name, bal)
{
term = months;
interestRate = rate;
}

void calculateInterest() override
{
    double interest =
        getBalance() * interestRate * term / (100 * 12);

    cout << "\nFixed Deposit Interest\n";
    cout << "Interest Rate : " << interestRate << "%" << endl;
    cout << "Term          : " << term << " months" << endl;
    cout << "Interest      : Rs. "
         << interest << endl;
    cout << "Maturity      : Rs. "
         << getBalance() + interest << endl;
}

void displayAccountInfo() const override
{
    cout << "\n===== FIXED DEPOSIT ACCOUNT =====\n";
    BankAccount::displayAccountInfo();
    cout << "Term          : " << term << " months" << endl;
    cout << "Interest Rate : " << interestRate << "%" << endl;
}

};

int main()
{
vector<BankAccount*> accounts;

int choice;

do
{
    cout << "\n========================================\n";
    cout << "          BANKING SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Create Savings Account\n";
    cout << "2. Create Checking Account\n";
    cout << "3. Create Fixed Deposit Account\n";
    cout << "4. Display All Accounts\n";
    cout << "5. Deposit Money\n";
    cout << "6. Withdraw Money\n";
    cout << "7. Calculate Interest\n";
    cout << "8. Check Overdraft\n";
    cout << "9. Exit\n";
    cout << "========================================\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string accNo, name;
        double balance, rate;

        cin.ignore();

        cout << "\nEnter account number: ";
        getline(cin, accNo);

        cout << "Enter account holder name: ";
        getline(cin, name);

        cout << "Enter initial balance: ";
        cin >> balance;

        cout << "Enter interest rate (%): ";
        cin >> rate;

        if (balance < 0 || rate < 0)
        {
            cout << "Invalid input.\n";
            continue;
        }

        accounts.push_back(
            new SavingsAccount(
                accNo, name, balance, rate
            )
        );

        cout << "\nSavings account created successfully!\n";
    }

    else if (choice == 2)
    {
        string accNo, name;
        double balance, overdraft;

        cin.ignore();

        cout << "\nEnter account number: ";
        getline(cin, accNo);

        cout << "Enter account holder name: ";
        getline(cin, name);

        cout << "Enter initial balance: ";
        cin >> balance;

        cout << "Enter overdraft limit: ";
        cin >> overdraft;

        if (balance < 0 || overdraft < 0)
        {
            cout << "Invalid input.\n";
            continue;
        }

        accounts.push_back(
            new CheckingAccount(
                accNo, name, balance, overdraft
            )
        );

        cout << "\nChecking account created successfully!\n";
    }

    else if (choice == 3)
    {
        string accNo, name;
        double balance, rate;
        int term;

        cin.ignore();

        cout << "\nEnter account number: ";
        getline(cin, accNo);

        cout << "Enter account holder name: ";
        getline(cin, name);

        cout << "Enter deposit amount: ";
        cin >> balance;

        cout << "Enter term (months): ";
        cin >> term;

        cout << "Enter interest rate (%): ";
        cin >> rate;

        if (balance < 0 || term <= 0 || rate < 0)
        {
            cout << "Invalid input.\n";
            continue;
        }

        accounts.push_back(
            new FixedDepositAccount(
                accNo, name, balance, term, rate
            )
        );

        cout << "\nFixed deposit account created successfully!\n";
    }

    else if (choice == 4)
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
        }
        else
        {
            cout << "\n===== ALL ACCOUNTS =====\n";

            for (BankAccount* account : accounts)
            {
                account->displayAccountInfo();
            }
        }
    }

    else if (choice == 5)
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            continue;
        }

        string accNo;
        double amount;

        cin.ignore();

        cout << "Enter account number: ";
        getline(cin, accNo);

        cout << "Enter amount to deposit: ";
        cin >> amount;

        bool found = false;

        for (BankAccount* account : accounts)
        {
            if (account->getAccountNumber() == accNo)
            {
                account->deposit(amount);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Account not found.\n";
        }
    }

    else if (choice == 6)
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            continue;
        }

        string accNo;
        double amount;

        cin.ignore();

        cout << "Enter account number: ";
        getline(cin, accNo);

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        bool found = false;

        for (BankAccount* account : accounts)
        {
            if (account->getAccountNumber() == accNo)
            {
                account->withdraw(amount);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Account not found.\n";
        }
    }

    else if (choice == 7)
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            continue;
        }

        string accNo;

        cin.ignore();

        cout << "Enter account number: ";
        getline(cin, accNo);

        bool found = false;

        for (BankAccount* account : accounts)
        {
            if (account->getAccountNumber() == accNo)
            {
                account->calculateInterest();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Account not found.\n";
        }
    }

    else if (choice == 8)
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            continue;
        }

        string accNo;

        cin.ignore();

        cout << "Enter account number: ";
        getline(cin, accNo);

        bool found = false;

        for (BankAccount* account : accounts)
        {
            if (account->getAccountNumber() == accNo)
            {
                account->checkOverdraft();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Account not found.\n";
        }
    }

    else if (choice == 9)
    {
        cout << "\nThank you for using Banking System!\n";
    }

    else
    {
        cout << "\nInvalid choice. Please try again.\n";
    }

} while (choice != 9);

for (BankAccount* account : accounts)
{
    delete account;
}
accounts.clear();
return 0;
}
