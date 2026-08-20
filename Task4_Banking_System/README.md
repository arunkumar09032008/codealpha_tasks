# Task 4: Banking System

## Description
A C++ object-oriented banking application that manages customers, accounts, deposits, withdrawals, fund transfers, and transaction logs with file persistence across sessions.

## Features
- Object-Oriented Design: `Customer`, `Account`, `Transaction`, and `BankingSystem` classes.
- Account creation with initial deposit handling.
- Financial operations: Deposits, Withdrawals with balance validation, and Fund Transfers between accounts.
- Transaction History logging for every transaction with timestamp.
- Persistent file storage (`data/customers.txt`, `data/accounts.txt`, `data/transactions.txt`).

## How to Compile and Run

Using `g++`:
```bash
g++ -std=c++11 -Iinclude src/main.cpp -o Banking_System.exe
./Banking_System.exe
```
