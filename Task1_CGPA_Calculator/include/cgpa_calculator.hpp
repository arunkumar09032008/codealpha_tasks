#ifndef CGPA_CALCULATOR_HPP
#define CGPA_CALCULATOR_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

struct Course {
    std::string name;
    std::string gradeLetter;
    double gradePoint;
    double creditHours;

    Course(const std::string& n, const std::string& g, double points, double credits)
        : name(n), gradeLetter(g), gradePoint(points), creditHours(credits) {}
};

class CGPACalculator {
private:
    std::vector<Course> courses;

public:
    static double convertGradeToPoints(std::string gradeStr) {
        // Normalize string to uppercase
        std::transform(gradeStr.begin(), gradeStr.end(), gradeStr.begin(), ::toupper);
        
        if (gradeStr == "A+" || gradeStr == "A") return 4.0;
        if (gradeStr == "A-") return 3.7;
        if (gradeStr == "B+") return 3.3;
        if (gradeStr == "B")  return 3.0;
        if (gradeStr == "B-") return 2.7;
        if (gradeStr == "C+") return 2.3;
        if (gradeStr == "C")  return 2.0;
        if (gradeStr == "C-") return 1.7;
        if (gradeStr == "D+") return 1.3;
        if (gradeStr == "D")  return 1.0;
        if (gradeStr == "F")  return 0.0;
        
        // Try parsing numerical value directly if letter grade not matched
        try {
            double val = std::stod(gradeStr);
            if (val >= 0.0 && val <= 4.0) return val;
        } catch (...) {}

        return -1.0; // Invalid grade
    }

    void addCourse(const std::string& name, const std::string& gradeLetter, double credits) {
        double points = convertGradeToPoints(gradeLetter);
        if (points < 0) {
            std::cout << "Invalid grade entered for course: " << name << ". Course omitted.\n";
            return;
        }
        courses.emplace_back(name, gradeLetter, points, credits);
    }

    double calculateTotalCredits() const {
        double totalCredits = 0.0;
        for (const auto& course : courses) {
            totalCredits += course.creditHours;
        }
        return totalCredits;
    }

    double calculateTotalGradePoints() const {
        double totalPoints = 0.0;
        for (const auto& course : courses) {
            totalPoints += (course.gradePoint * course.creditHours);
        }
        return totalPoints;
    }

    double calculateCGPA() const {
        double totalCredits = calculateTotalCredits();
        if (totalCredits <= 0.0) return 0.0;
        return calculateTotalGradePoints() / totalCredits;
    }

    void displayReport() const {
        if (courses.empty()) {
            std::cout << "\nNo courses added yet.\n";
            return;
        }

        std::cout << "\n=======================================================\n";
        std::cout << "               STUDENT ACADEMIC REPORT                 \n";
        std::cout << "=======================================================\n";
        std::cout << std::left << std::setw(20) << "Course Name" 
                  << std::setw(10) << "Grade" 
                  << std::setw(14) << "Grade Point" 
                  << std::setw(12) << "Credits" << "\n";
        std::cout << "-------------------------------------------------------\n";

        for (const auto& c : courses) {
            std::cout << std::left << std::setw(20) << c.name 
                      << std::setw(10) << c.gradeLetter 
                      << std::setw(14) << std::fixed << std::setprecision(2) << c.gradePoint 
                      << std::setw(12) << std::fixed << std::setprecision(1) << c.creditHours << "\n";
        }

        std::cout << "-------------------------------------------------------\n";
        std::cout << "Total Credits Earned : " << std::fixed << std::setprecision(1) << calculateTotalCredits() << "\n";
        std::cout << "Total Grade Points   : " << std::fixed << std::setprecision(2) << calculateTotalGradePoints() << "\n";
        std::cout << "Final CGPA / GPA     : " << std::fixed << std::setprecision(2) << calculateCGPA() << " / 4.00\n";
        std::cout << "=======================================================\n";
    }

    void clear() {
        courses.clear();
    }
};

#endif // CGPA_CALCULATOR_HPP
