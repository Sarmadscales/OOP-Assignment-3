/*
 * ============================================================================
 * File: User.h
 * Description: Header file for Smart University Management System
 * Contains: Class declarations for User, Student, Teacher, and Admin
 * Demonstrates: Hierarchical Inheritance in C++
 * ============================================================================
 * Student: Muhammad Sarmad
 * Roll No: L1F24BSAI0059
 * Course: Object Oriented Programming (CP223-F25-BS-AI-F24-AC2)
 * ============================================================================
 */

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// BASE CLASS: User
// Description: Base class containing common attributes and behaviors
//              for all users in the university system
// Access Specifier: Protected members allow derived class access
// ============================================================================
class User {
protected:
    string name;    // User's name (protected for derived class access)
    int id;         // User's unique ID

public:
    // Constructor with initializer list
    User(string n, int i);
    
    // Destructor
    ~User();
    
    // Common behaviors
    void login() const;         // const function - won't modify object
    void logout() const;        // const function - won't modify object
    void displayInfo() const;   // Display user information
    
    // Getters
    string getName() const;
    int getId() const;
};

// ============================================================================
// DERIVED CLASS 1: Student
// Description: Represents a student user, inherits from User
// Inheritance Type: Public (IS-A relationship: Student IS-A User)
// Unique Feature: registerCourse() method
// ============================================================================
class Student : public User {
private:
    string program;     // Student's enrolled program

public:
    // Constructor - calls base class constructor
    Student(string n, int i, string p);
    
    // Destructor
    ~Student();
    
    // Unique functionality for Student
    void registerCourse(string course) const;
    
    // Display complete student information
    void displayStudentInfo() const;
    
    // Getter
    string getProgram() const;
};

// ============================================================================
// DERIVED CLASS 2: Teacher
// Description: Represents a teacher user, inherits from User
// Inheritance Type: Public (IS-A relationship: Teacher IS-A User)
// Unique Feature: uploadMarks() method
// ============================================================================
class Teacher : public User {
private:
    string department;  // Teacher's department

public:
    // Constructor - calls base class constructor
    Teacher(string n, int i, string d);
    
    // Destructor
    ~Teacher();
    
    // Unique functionality for Teacher
    void uploadMarks(string course, int marks) const;
    
    // Display complete teacher information
    void displayTeacherInfo() const;
    
    // Getter
    string getDepartment() const;
};

// ============================================================================
// DERIVED CLASS 3: Admin
// Description: Represents an admin user, inherits from User
// Inheritance Type: Public (IS-A relationship: Admin IS-A User)
// Unique Feature: manageSystem() method
// ============================================================================
class Admin : public User {
private:
    string role;    // Admin's specific role

public:
    // Constructor - calls base class constructor
    Admin(string n, int i, string r);
    
    // Destructor
    ~Admin();
    
    // Unique functionality for Admin
    void manageSystem(string task) const;
    
    // Display complete admin information
    void displayAdminInfo() const;
    
    // Getter
    string getRole() const;
};

#endif // USER_H