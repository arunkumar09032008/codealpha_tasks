#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include <iostream>
#include <vector>
#include <iomanip>

class SudokuSolver {
public:
    static const int SIZE = 9;

private:
    int grid[SIZE][SIZE];

public:
    SudokuSolver() {
        resetGrid();
    }

    void resetGrid() {
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                grid[r][c] = 0;
            }
        }
    }

    void setGrid(const int initialGrid[SIZE][SIZE]) {
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                grid[r][c] = initialGrid[r][c];
            }
        }
    }

    int getCell(int r, int c) const {
        return grid[r][c];
    }

    void setCell(int r, int c, int val) {
        grid[r][c] = val;
    }

    // Check if num can be placed at grid[row][col] according to Sudoku rules
    bool isValid(int row, int col, int num) const {
        // Row constraint
        for (int c = 0; c < SIZE; ++c) {
            if (grid[row][c] == num) return false;
        }

        // Column constraint
        for (int r = 0; r < SIZE; ++r) {
            if (grid[r][col] == num) return false;
        }

        // 3x3 subgrid constraint
        int startRow = row - (row % 3);
        int startCol = col - (col % 3);
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (grid[startRow + r][startCol + c] == num) return false;
            }
        }

        return true;
    }

    // Recursive Backtracking algorithm to solve Sudoku
    bool solve() {
        int row = -1;
        int col = -1;
        bool isEmpty = false;

        // Find an empty cell (cell with value 0)
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                if (grid[r][c] == 0) {
                    row = r;
                    col = c;
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) break;
        }

        // No empty cell left, Sudoku is solved!
        if (!isEmpty) return true;

        // Try numbers 1 through 9
        for (int num = 1; num <= 9; ++num) {
            if (isValid(row, col, num)) {
                grid[row][col] = num;

                if (solve()) {
                    return true;
                }

                // Backtrack
                grid[row][col] = 0;
            }
        }

        return false; // Trigger backtracking
    }

    void displayGrid() const {
        std::cout << "  +-------+-------+-------+\n";
        for (int r = 0; r < SIZE; ++r) {
            std::cout << "  | ";
            for (int c = 0; c < SIZE; ++c) {
                if (grid[r][c] == 0) {
                    std::cout << ". ";
                } else {
                    std::cout << grid[r][c] << " ";
                }

                if ((c + 1) % 3 == 0) {
                    std::cout << "| ";
                }
            }
            std::cout << "\n";
            if ((r + 1) % 3 == 0) {
                std::cout << "  +-------+-------+-------+\n";
            }
        }
    }
};

#endif // SUDOKU_SOLVER_HPP
