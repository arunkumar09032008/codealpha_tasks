# Task 1: CGPA Calculator

## Description
A C++ application to calculate a student's semester GPA and cumulative CGPA based on individual course credit hours and letter grades/grade points.

## Features
- Interactive prompt for course count, course names, grades, and credit hours.
- Flexible grade input (Supports letter grades `A+` through `F`, or direct numerical grade points `0.0 - 4.0`).
- Input validation to ensure accurate calculations.
- Formatted tabular academic transcript report showing credits, total grade points, and final CGPA.

## How to Compile and Run

Using `g++`:
```bash
g++ -std=c++11 -Iinclude src/main.cpp -o CGPA_Calculator.exe
./CGPA_Calculator.exe
```
