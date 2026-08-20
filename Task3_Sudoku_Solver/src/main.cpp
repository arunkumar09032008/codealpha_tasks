#include "../include/sudoku_solver.hpp"
#include <iostream>
#include <limits>

const int EASY_PUZZLE[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

const int HARD_PUZZLE[9][9] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 9, 0, 2, 0, 0},
    {0, 5, 0, 0, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 4, 5, 7, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 3, 0},
    {0, 0, 1, 0, 0, 0, 0, 6, 8},
    {0, 0, 8, 5, 0, 0, 0, 1, 0},
    {0, 9, 0, 0, 0, 0, 4, 0, 0}
};

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    SudokuSolver solver;
    int choice = 0;

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "         CODEALPHA SUDOKU SOLVER         \n";
        std::cout << "=========================================\n";
        std::cout << " 1. Solve Sample Puzzle (Easy)\n";
        std::cout << " 2. Solve Sample Puzzle (Hard)\n";
        std::cout << " 3. Input Custom Sudoku Puzzle\n";
        std::cout << " 4. Exit\n";
        std::cout << "=========================================\n";
        std::cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearBuffer();
            continue;
        }

        if (choice == 1) {
            solver.setGrid(EASY_PUZZLE);
            std::cout << "\n[Initial Easy Puzzle Grid]:\n";
            solver.displayGrid();

            std::cout << "\nSolving puzzle via Backtracking...\n";
            if (solver.solve()) {
                std::cout << "\n[SOLVED SUDOKU GRID]:\n";
                solver.displayGrid();
            } else {
                std::cout << "\n[ERROR] No solution exists for this Sudoku grid.\n";
            }
        } else if (choice == 2) {
            solver.setGrid(HARD_PUZZLE);
            std::cout << "\n[Initial Hard Puzzle Grid]:\n";
            solver.displayGrid();

            std::cout << "\nSolving puzzle via Backtracking...\n";
            if (solver.solve()) {
                std::cout << "\n[SOLVED SUDOKU GRID]:\n";
                solver.displayGrid();
            } else {
                std::cout << "\n[ERROR] No solution exists for this Sudoku grid.\n";
            }
        } else if (choice == 3) {
            solver.resetGrid();
            std::cout << "\nEnter 81 numbers for 9x9 grid (row by row, use 0 for empty cells):\n";
            int val;
            bool valid = true;
            for (int r = 0; r < 9; ++r) {
                for (int c = 0; c < 9; ++c) {
                    if (!(std::cin >> val) || val < 0 || val > 9) {
                        std::cout << "Invalid cell entry at (" << r+1 << "," << c+1 << "). Entry must be 0-9.\n";
                        valid = false;
                        clearBuffer();
                        break;
                    }
                    solver.setCell(r, c, val);
                }
                if (!valid) break;
            }

            if (valid) {
                std::cout << "\n[Your Input Puzzle Grid]:\n";
                solver.displayGrid();

                std::cout << "\nSolving custom puzzle...\n";
                if (solver.solve()) {
                    std::cout << "\n[SOLVED SUDOKU GRID]:\n";
                    solver.displayGrid();
                } else {
                    std::cout << "\n[ERROR] No valid solution exists for this grid configuration.\n";
                }
            }
        } else if (choice == 4) {
            std::cout << "Exiting Sudoku Solver. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please choose 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}
