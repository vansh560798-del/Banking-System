# Banking System – C++

## 📌 Project Description

The **Banking System** is a console-based C++ program designed to manage different types of bank accounts such as **Savings Account, Checking Account, and Fixed Deposit Account**.

The project demonstrates important **Object-Oriented Programming (OOP)** concepts including:

- Classes and Objects
- Inheritance
- Encapsulation
- Polymorphism
- Constructors
- Virtual Functions
- Dynamic Memory Allocation

## ✨ Features

- Create a Savings Account
- Create a Checking Account
- Create a Fixed Deposit Account
- Display all accounts
- Deposit money
- Withdraw money
- Calculate interest
- Check overdraft facility
- Input validation
- Multiple account types using inheritance and polymorphism

## 🛠️ Technologies Used

- **Language:** C++
- **Compiler:** GCC / Clang
- **Concepts:** OOP, Inheritance, Encapsulation, Polymorphism

## 📂 Project Structure

```text
Project4/
│
├── Project4.cpp
└── README.md
```

## 🧩 Classes Used

### 1. BankAccount

The base class containing common account information:

- Account Number
- Account Holder Name
- Balance

It provides functions for:

- Deposit
- Withdrawal
- Interest calculation
- Overdraft checking
- Displaying account information

### 2. SavingsAccount

Derived from `BankAccount`.

Additional attribute:

- Interest Rate

It calculates interest based on the current balance and interest rate.

### 3. CheckingAccount

Derived from `BankAccount`.

Additional attribute:

- Overdraft Limit

It allows withdrawals using the available overdraft limit.

### 4. FixedDepositAccount

Derived from `BankAccount`.

Additional attributes:

- Term in months
- Interest Rate

It calculates interest and displays the maturity amount.

## 📋 Main Menu

```text
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Display All Accounts
5. Deposit Money
6. Withdraw Money
7. Calculate Interest
8. Check Overdraft
9. Exit
```

## ▶️ How to Run

### Compile

```bash
g++ Project4.cpp -o Project4
```

### Run

```bash
./Project4
```

On Windows:

```bash
Project4.exe
```

## 🧠 OOP Concepts Demonstrated

### Encapsulation

Account data members are kept private and accessed through public member functions.

### Inheritance

`SavingsAccount`, `CheckingAccount`, and `FixedDepositAccount` inherit from `BankAccount`.

### Polymorphism

Virtual functions allow derived account classes to provide their own implementations of functions such as:

```cpp
calculateInterest()
displayAccountInfo()
withdraw()
checkOverdraft()
```

### Dynamic Memory Allocation

Bank accounts are created dynamically and stored using:

```cpp
vector<BankAccount*>
```

## 🎥 Project Video

**Video Link:**  
https://drive.google.com/drive/folders/1-g8HgSpjR3PHpT8zbff1Fs6vbITzXV8a?usp=sharing

## 👨‍💻 Author

**Vansh Soni**

---

## ✅ Conclusion

This project demonstrates how C++ Object-Oriented Programming concepts can be used to create a practical **Banking System** that supports multiple account types, deposits, withdrawals, interest calculations, and overdraft management.
