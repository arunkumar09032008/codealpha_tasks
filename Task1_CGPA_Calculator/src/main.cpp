#include "../include/cgpa_calculator.hpp"
#include <iostream>
#include <limits>
#include <string>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    CGPACalculator calc;
    int numCourses = 0;

    std::cout << "=========================================\n";
    std::cout << "      CODEALPHA CGPA CALCULATOR          \n";
    std::cout << "=========================================\n\n";

    std::cout << "Enter the number of courses taken: ";
    while (!(std::cin >> numCourses) || numCourses <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for number of courses: ";
        clearInputBuffer();
    }
    clearInputBuffer();

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Note on Grades: You can enter letter grades\n";
    std::cout << "(A+, A, A-, B+, B, B-, C+, C, C-, D, F) or grade points (0.0 - 4.0)\n";
    std::cout << "-----------------------------------------\n\n";

    for (int i = 1; i <= numCourses; ++i) {
        std::string courseName;
        std::string grade;
        double credits = 0.0;

        std::cout << "Course " << i << " Details:\n";
        std::cout << "  Course Name / Code: ";
        std::getline(std::cin, courseName);

        while (true) {
            std::cout << "  Grade (e.g. A+, B, 3.5): ";
            std::getline(std::cin, grade);
            if (CGPACalculator::convertGradeToPoints(grade) >= 0.0) {
                break;
            }
            std::cout << "  Invalid grade value. Try again.\n";
        }

        while (true) {
            std::cout << "  Credit Hours (e.g. 3.0): ";
            if (std::cin >> credits && credits > 0.0) {
                clearInputBuffer();
                break;
            }
            std::cout << "  Invalid credit hours. Must be > 0.\n";
            clearInputBuffer();
        }

        calc.addCourse(courseName, grade, credits);
        std::cout << "\n";
    }

    calc.displayReport();

    return 0;
}
