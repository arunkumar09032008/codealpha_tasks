# 📹 Video Presentation Scripts & LinkedIn Submission Guide

This document provides word-for-word presentation scripts, screen recording instructions, and LinkedIn post templates for your **CodeAlpha C++ Internship Projects** video submission.

---

## 🎬 Recording Setup Tips
- **Free Screen Recorders**: OBS Studio, Loom, or Windows Game Bar (`Win + G`).
- **Resolution**: 1080p (Full HD).
- **Structure**: You can record one combined 3-5 minute video covering all 4 tasks, or separate short videos for each task.

---

# 📌 Task 1: CGPA Calculator Video Script

### 🖥️ On-Screen Demonstration
1. Open terminal and run `.\Task1_CGPA_Calculator\CGPA_Calculator.exe`.
2. Input number of courses (e.g., `3`).
3. Enter course details:
   - Course 1: `Data Structures`, Grade: `A`, Credits: `4`
   - Course 2: `Algorithms`, Grade: `A-`, Credits: `3`
   - Course 3: `Database Systems`, Grade: `B+`, Credits: `3`
4. Show the formatted output table and final CGPA score on screen.

### 🎙️ Word-for-Word Voiceover Script
> "Hello everyone! I'm excited to share **Task 1: CGPA Calculator**, developed during my C++ Programming Internship at **CodeAlpha**.
> 
> In this project, I built a console application in C++ that calculates a student's semester GPA and cumulative CGPA. 
> 
> Let's run the program. The system asks for the number of courses taken. I'll enter 3 courses. 
> For each course, it accepts the course name, letter grade (such as A, A-, B+), and credit hours. 
> 
> Behind the scenes, the program maps standard letter grades to grade points on a 4.0 scale. It calculates total credits and total grade points using the formula `Total Grade Points / Total Credit Hours`. 
> 
> As you can see, the program outputs a clean academic transcript table displaying all individual grades and calculates the exact final CGPA. Thank you!"

---

# 📌 Task 2: Login & Registration System Video Script

### 🖥️ On-Screen Demonstration
1. Run `.\Task2_Login_System\Login_System.exe`.
2. Choose Option `1` (Register): Register username `alex` with password `password123`.
3. Try registering `alex` again to demonstrate duplicate username detection error.
4. Choose Option `2` (Login):
   - Type wrong password to show error handling.
   - Type correct password `password123` to show successful login.
5. Open `Task2_Login_System/data/users.txt` to show hashed password storage.

### 🎙️ Word-for-Word Voiceover Script
> "Hi everyone! Here is **Task 2: Login and Registration System** for the **CodeAlpha** C++ Internship.
> 
> This application handles secure user authentication in C++. 
> 
> First, let's register a new user named 'alex'. If I try to register the same username again, the system detects the duplicate and prevents duplicate entries.
> 
> Second, let's test the login functionality. If I enter an incorrect password, access is denied with a clear error message. When I enter the correct credentials, authentication succeeds and access is granted.
> 
> Most importantly, user credentials are not saved in plain text. Passwords are encrypted using a Salted Hashing algorithm before being stored in the database file. Thank you!"

---

# 📌 Task 3: Sudoku Solver Video Script

### 🖥️ On-Screen Demonstration
1. Run `.\Task3_Sudoku_Solver\Sudoku_Solver.exe`.
2. Select Option `1` (Solve Sample Easy Puzzle).
3. Show the unsolved 9x9 grid with `.` for empty cells.
4. Show how fast the Backtracking algorithm solves the puzzle and prints the complete grid.
5. Select Option `2` (Solve Sample Hard Puzzle) to show performance on complex puzzles.

### 🎙️ Word-for-Word Voiceover Script
> "Hello everyone! This is **Task 3: Sudoku Solver** created using C++ for my **CodeAlpha** internship.
> 
> This project implements a **Recursive Backtracking algorithm** to automatically solve any valid 9x9 Sudoku puzzle.
> 
> Let's select the sample puzzle. The initial grid is displayed with empty cells marked as dots. 
> 
> When I hit solve, the algorithm places numbers 1 through 9 while dynamically checking Sudoku constraints across rows, columns, and 3x3 sub-grids. If a conflict occurs, it recursively backtracks until the exact solution is found.
> 
> In less than a millisecond, the puzzle is solved and displayed in a formatted 9x9 grid layout! Thank you!"

---

# 📌 Task 4: Banking System Video Script

### 🖥️ On-Screen Demonstration
1. Run `.\Task4_Banking_System\Banking_System.exe`.
2. Select Option `1`: Create Account for customer `John Doe` with Account `#1001` and initial deposit `$1000`.
3. Select Option `1`: Create Account for customer `Jane Smith` with Account `#1002` and initial deposit `$500`.
4. Select Option `2`: Deposit `$200` into Account `#1001`.
5. Select Option `3`: Withdraw `$100` from Account `#1001`.
6. Select Option `4`: Transfer `$300` from `#1001` to `#1002`.
7. Select Option `5` & `6`: View account details and complete transaction history for Account `#1001`.

### 🎙️ Word-for-Word Voiceover Script
> "Hi everyone! Finally, I am presenting **Task 4: Banking System**, built for my C++ Internship at **CodeAlpha**.
> 
> This application is built using Object-Oriented Programming (OOP) principles in C++, featuring dedicated `Customer`, `Account`, and `Transaction` classes.
> 
> Let's demonstrate the features:
> 1. We create two customer bank accounts.
> 2. We perform a deposit of $200 and a withdrawal of $100. The system automatically validates account balances to prevent overdrafts.
> 3. We execute a direct fund transfer of $300 from Account 1001 to Account 1002.
> 4. We view the transaction history, which logs every transaction with unique IDs and timestamps.
> 
> All accounts and transaction histories are saved to disk, so state persists across restarts. Thank you **CodeAlpha** for this awesome learning experience!"

---

## 📲 LinkedIn Post Template for Submission

When posting your video on LinkedIn, copy and paste this text:

```markdown
🚀 Excited to complete my C++ Programming Internship tasks at @CodeAlpha! 💻✨

During this internship program, I developed 4 C++ projects demonstrating Core Object-Oriented Programming, Data Structures, Algorithms, and System Security:

1️⃣ Task 1: CGPA Calculator - GPA/CGPA computation with grade point mapping & transcript generation.
2️⃣ Task 2: Login and Registration System - Secure authentication with salted password hashing & file persistence.
3️⃣ Task 3: Sudoku Solver - 9x9 Sudoku solver using Recursive Backtracking algorithms.
4️⃣ Task 4: Banking System - Object-Oriented banking system with deposits, withdrawals, fund transfers & transaction logs.

🔗 GitHub Repository: https://github.com/arunkumar09032008/codealpha_tasks

Special thanks to @CodeAlpha for this incredible learning opportunity! 🎯

#CodeAlpha #Cpp #Programming #SoftwareEngineering #Internship #GitHub #ObjectOrientedProgramming #DataStructures #Coding
```
