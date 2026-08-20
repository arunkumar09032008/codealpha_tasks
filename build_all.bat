@echo off
echo ========================================================
echo Building CodeAlpha C++ Internship Projects
echo ========================================================

echo [1/4] Compiling Task 1: CGPA Calculator...
g++ -std=c++11 -ITask1_CGPA_Calculator/include Task1_CGPA_Calculator/src/main.cpp -o Task1_CGPA_Calculator/CGPA_Calculator.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Task 1 Compilation Failed!
    exit /b %ERRORLEVEL%
)

echo [2/4] Compiling Task 2: Login and Registration System...
g++ -std=c++11 -ITask2_Login_System/include Task2_Login_System/src/main.cpp -o Task2_Login_System/Login_System.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Task 2 Compilation Failed!
    exit /b %ERRORLEVEL%
)

echo [3/4] Compiling Task 3: Sudoku Solver...
g++ -std=c++11 -ITask3_Sudoku_Solver/include Task3_Sudoku_Solver/src/main.cpp -o Task3_Sudoku_Solver/Sudoku_Solver.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Task 3 Compilation Failed!
    exit /b %ERRORLEVEL%
)

echo [4/4] Compiling Task 4: Banking System...
g++ -std=c++11 -ITask4_Banking_System/include Task4_Banking_System/src/main.cpp -o Task4_Banking_System/Banking_System.exe
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Task 4 Compilation Failed!
    exit /b %ERRORLEVEL%
)

echo ========================================================
echo SUCCESS: All 4 CodeAlpha C++ Projects Compiled!
echo ========================================================
