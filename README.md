Password Strength Checker & Generator

The project is a simple yet powerful cybersecurity-based application developed in C that helps users create and evaluate secure passwords. The program analyzes a user-entered password by checking important security criteria such as minimum length, presence of uppercase and lowercase letters, digits, and special characters. Based on these checks, it classifies the password as weak, medium, or strong and provides feedback on how to improve it. If the password is weak, the user is given an option to generate a stronger password in two different ways: a completely random secure password or a personalized password based on user inputs like favorite color, word, and number. This project demonstrates key programming concepts such as string handling, loops, conditional statements, functions, and random number generation, while also highlighting practical cybersecurity principles like password strength and user data protection.


#Guessing Game in C


##Features

Random number generation using rand()<br>
Three difficulty levels<br>
Limited guessing attempts<br>
Hint system:<br>
Too high<br>
Too low<br>
Very close hint<br>
Score system<br>
Displays total attempts<br>
Simple and beginner-friendly C project<br>


##Difficulty Levels

Level	Number Range	Attempts<br>
Easy	1 – 9	10 Attempts<br>
Medium	10 – 99	15 Attempts<br>
Hard	100 – 999	20 Attempts

##Technologies Used

C Programming Language<br>
Standard Libraries:<br>
stdio.h<br>
stdlib.h<br>
time.h<br>


##How the Game Works<br>
User selects a difficulty level.<br>
Program generates a random number.<br>
User enters guesses.<br>
Program gives hints:<br>
Low guess<br>
High guess<br>
Very close to the answer<br>
If the user guesses correctly:<br>
Winning message is displayed<br>
Score is shown<br>
If attempts finish:<br>
Game over message appears<br>
Correct number is displayed<br>


##Concepts Used
Functions<br>
Loops<br>
Conditional Statements<br>
Random Number Generation<br>
User Input Handling<br>
Switch Case<br>
Variables and Operators<br>


##Sample Output
enter 1 for easy level:<br>
enter 2 for medium level:<br>
enter 3 for hard level: 1<br>


you can guess number 10 times:<br>
Guessing the number between (1-9): 5<br>
Not matching and low! Please Try Again!<br>
You are very close to win! Please Try Again:<br>


##Learning Objectives<br>
This project helps me understand:<br>

Basic game logic in C<br>
Use of functions<br>
Random number generation<br>
Loop control<br>
Score calculation<br>

# Employee Management System

A console-based Employee Management System developed in C that manages employee records using file handling. The system allows administrators to add, update, search, and delete employee records while also providing salary and department-based analysis.

## Features

### Employee Record Management
- Add new employee records
- Update existing employee information
- Search employees by name
- Delete employee records
- Prevent duplicate employee IDs during employee registration

### Employee Analysis
- Display employee with the highest salary
- Display employee with the lowest salary
- Show employees from the IT Support department
- Display employees earning above the average salary
- Count employees in each department

### Security
- Password-protected access
- Maximum of three login attempts

### File Handling
- Stores employee data in a text file
- Supports reading, writing, updating, and deleting records


## Technologies Used

- C Programming Language
- Structures
- Functions
- File Handling
- String Manipulation



## Employee Information

The system stores the following employee details:

- Employee ID
- Employee Name
- Gender
- Age
- Department
- Salary


## Departments

The project supports the following departments:

- Software Development
- Network Administration
- Data Management
- Cybersecurity
- IT Support



## Menu Structure

### Main Menu


1. Update Employee Data
2. Search Employee
3. Delete Employee
4. Add Employee
5. Employee Analysis


### Analysis Menu

1. Highest and Lowest Salary
2. Employees from IT Department
3. Employees Above Average Salary
4. Count Employees in Each Department


## Sample Login

Enter the password to access employee data:
Project@123



## Learning Outcomes

This project demonstrates:

- Structure implementation in C
- File handling operations
- CRUD (Create, Read, Update, Delete) operations
- Menu-driven programming
- Data processing and analysis
- Basic authentication system



## Limitations

- Data is stored in a text file instead of a database.
- Employee names cannot contain spaces.
- Search functionality is limited to employee names.
- Password is hardcoded in the source code.
- No data encryptions



##Conclusion

The Employee Management System is a console-based application developed in C that demonstrates the practical use of file handling, structures, functions, and menu-driven programming. The project provides an efficient way to manage employee records by allowing users to add, update, search, and delete employee information while maintaining data persistence through files.

In addition to basic employee management operations, the system offers analytical features such as identifying the highest and lowest salary employees, displaying employees from specific departments, calculating employees earning above the average salary, and counting employees in each department. These features enhance the functionality of the application and provide meaningful insights into employee data.

Overall, this project helped strengthen my understanding of C programming concepts, file management, data processing, and problem-solving techniques. It serves as a strong foundation for developing more advanced management systems with database integration, improved security, and graphical user interfaces in the future.

