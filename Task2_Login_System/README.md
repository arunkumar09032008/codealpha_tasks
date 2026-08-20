# Task 2: Login and Registration System

## Description
A C++ authentication system with secure file storage, password hashing (Salted FNV-1a algorithm), input validation, and user identity verification.

## Features
- User Registration with duplicate username prevention.
- Password hashing before saving to database file (`data/users.txt`).
- Input validation (non-empty username/password, length checks, invalid characters filter).
- Authenticated Login with user verification.
- Persistent user records saved in text file format.

## How to Compile and Run

Using `g++`:
```bash
g++ -std=c++11 -Iinclude src/main.cpp -o Login_System.exe
./Login_System.exe
```
