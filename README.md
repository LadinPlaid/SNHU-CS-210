# CS-210 – C++ Programming Projects

## Overview

These projects were completed for **CS-210: Programming Languages** at Southern New Hampshire University. They demonstrate object-oriented programming, file handling, data processing, and console application development using C++.

The repository includes two applications: the **Corner Grocer Item Tracker** and the **Airgead Banking Investment Calculator**.

## Project Three – Corner Grocer Item Tracker

The purpose of this project was to create an application that reads purchase records from a text file and calculates how frequently each item was purchased.

### Features

- Search for an individual item’s purchase frequency.
- Display all items and their purchase counts.
- Display a text histogram of item frequencies.
- Automatically create a `frequency.dat` backup file.
- Validate menu selections and report errors when the input file cannot be opened.

### Project Files

**CornerGrocer.cpp**  
Contains the `ItemTracker` class, file-processing logic, reporting functions, and interactive menu.

**CS210_Project_Three_Input_File.txt**  
Contains the purchase records used by the application.

### Implementation

The application uses a `std::map` to associate each item with its purchase count. The `ItemTracker` class organizes the methods for loading records, searching items, displaying reports, and writing backup data.

## Project Two – Airgead Banking Investment Calculator

The purpose of this project was to create an application that illustrates investment growth based on an initial investment, monthly deposits, an annual interest rate, and a selected number of years.

### Features

- Accept investment information through console prompts.
- Display a summary of the entered values.
- Generate annual balance and earned-interest reports.
- Show projections with and without additional monthly deposits.
- Allow users to repeat calculations with different inputs.

### Project Files

**Investment.h**  
Declares the `Investment` class, its data members, and reporting methods.

**Investment.cpp**  
Implements the investment calculations and formatted reports.

**main.cpp**  
Handles user input, creates the investment object, and controls the application flow.

### Implementation

The application separates console interaction from the `Investment` class. The current report without monthly deposits calculates interest annually, while the report with monthly deposits calculates interest monthly.

## Technologies Used

- C++
- Standard Template Library (`std::map`)
- File Input and Output
- Object-Oriented Programming
- Console Input Validation
- Formatted Output

## Future Improvements

- Add automated tests for purchase counting and investment calculations.
- Improve validation of investment inputs.
- Use consistent compounding schedules across investment reports.
- Report backup file creation errors.
- Add build and execution instructions for both applications.

## What I Learned

These projects strengthened my understanding of class design, file processing, and organizing application logic in C++.

The Corner Grocer project introduced practical experience reading external files and converting records into useful reports. The investment calculator reinforced the use of classes, repeated calculations, and formatted output.

Both projects helped me recognize the importance of clear documentation, input validation, and separating responsibilities to make code easier to understand and maintain.

## Author

**Jacob Hastert**  
CS-210: Programming Languages  
Southern New Hampshire University
