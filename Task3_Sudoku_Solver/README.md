# Task 3: Sudoku Solver

## Description
A C++ application that solves any valid 9x9 Sudoku puzzle using a recursive backtracking algorithm while satisfying standard Sudoku row, column, and 3x3 subgrid constraints.

## Features
- 2D grid representation for 9x9 Sudoku puzzles.
- Recursive Backtracking algorithm with constraint checking.
- Clean ASCII grid visualization for puzzle display before and after solving.
- Built-in sample puzzles (Easy & Hard test cases).
- Option to input custom puzzles row-by-row.

## How to Compile and Run

Using `g++`:
```bash
g++ -std=c++11 -Iinclude src/main.cpp -o Sudoku_Solver.exe
./Sudoku_Solver.exe
```
