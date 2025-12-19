/*
 * ============================================================================
 * File: User.cpp
 * Description: Implementation file for Smart University Management System
 * Contains: Function definitions for User, Student, Teacher, and Admin
 * Demonstrates: Constructor/Destructor chaining in hierarchical inheritance
 * ============================================================================
 * Student: Muhammad Sarmad
 * Roll No: L1F24BSAI0059
 * Course: Object Oriented Programming (CP223-F25-BS-AI-F24-AC2)
 * ============================================================================
 */

#include "User.h"

// ============================================================================
// USER CLASS IMPLEMENTATION (Base Class)
// ============================================================================

// Constructor with initializer list - efficient initialization
User::User(string n, int i) : name(n), id(i) {
    cout << "[CONSTRUCTOR] User class constructor called" << endl;
    cout << "              -> User created: " << name << " (ID: " << id << ")" << endl;
}

// Destructor - called during object cleanup
User::~User() {
    cout << "[DESTRUCTOR] User class destructor called" << endl;
    cout << "             -> User destroyed: " << name << endl;
}

// Login functionality - const function (doesn't modify object)
void User::login() const {
    cout << ">> " << name << " (ID: " << id << ") has logged into the system." << endl;
}

// Logout functionality - const function
void User::logout() const {
    cout << ">> " << name << " (ID: " << id << ") has logged out of the system." << endl;
}

// Display basic user information
void User::displayInfo() const {
    cout << "   Name: " << name << endl;
    cout << "   ID: " << id << endl;
}

// Getters
string User::getName() const { return name; }
int User::getId() const { return id; }

// ============================================================================
// STUDENT CLASS IMPLEMENTATION (Derived Class 1)
// Constructor Order: User() -> Student() (Base to Derived)
// Destructor Order: ~Student() -> ~User() (Derived to Base)
// ============================================================================

// Constructor - initializer list calls base class constructor first
Student::Student(string n, int i, string p) : User(n, i), program(p) {
    cout << "[CONSTRUCTOR] Student class constructor called" << endl;
    cout << "              -> Student created: " << name << endl;
    cout << "              -> Program: " << program << endl;
}

// Destructor
Student::~Student() {
    cout << "[DESTRUCTOR] Student class destructor called" << endl;
    cout << "             -> Student destroyed: " << name << endl;
}

// Unique functionality - register for a course
void Student::registerCourse(string course) const {
    cout << ">> Student " << name << " has registered for: " << course << endl;
}

// Display complete student information
void Student::displayStudentInfo() const {
    cout << "+----------------------------------+" << endl;
    cout << "|      STUDENT INFORMATION         |" << endl;
    cout << "+----------------------------------+" << endl;
    displayInfo();  // Call base class function
    cout << "   Program: " << program << endl;
    cout << "+----------------------------------+" << endl;
}

// Getter
string Student::getProgram() const { return program; }

// ============================================================================
// TEACHER CLASS IMPLEMENTATION (Derived Class 2)
// Constructor Order: User() -> Teacher() (Base to Derived)
// Destructor Order: ~Teacher() -> ~User() (Derived to Base)
// ============================================================================

// Constructor - initializer list calls base class constructor first
Teacher::Teacher(string n, int i, string d) : User(n, i), department(d) {
    cout << "[CONSTRUCTOR] Teacher class constructor called" << endl;
    cout << "              -> Teacher created: " << name << endl;
    cout << "              -> Department: " << department << endl;
}

// Destructor
Teacher::~Teacher() {
    cout << "[DESTRUCTOR] Teacher class destructor called" << endl;
    cout << "             -> Teacher destroyed: " << name << endl;
}

// Unique functionality - upload marks for a course
void Teacher::uploadMarks(string course, int marks) const {
    cout << ">> Teacher " << name << " uploaded marks (" << marks << "/100) for: " << course << endl;
}

// Display complete teacher information
void Teacher::displayTeacherInfo() const {
    cout << "+----------------------------------+" << endl;
    cout << "|      TEACHER INFORMATION         |" << endl;
    cout << "+----------------------------------+" << endl;
    displayInfo();  // Call base class function
    cout << "   Department: " << department << endl;
    cout << "+----------------------------------+" << endl;
}

// Getter
string Teacher::getDepartment() const { return department; }

// ============================================================================
// ADMIN CLASS IMPLEMENTATION (Derived Class 3)
// Constructor Order: User() -> Admin() (Base to Derived)
// Destructor Order: ~Admin() -> ~User() (Derived to Base)
// ============================================================================

// Constructor - initializer list calls base class constructor first
Admin::Admin(string n, int i, string r) : User(n, i), role(r) {
    cout << "[CONSTRUCTOR] Admin class constructor called" << endl;
    cout << "              -> Admin created: " << name << endl;
    cout << "              -> Role: " << role << endl;
}

// Destructor
Admin::~Admin() {
    cout << "[DESTRUCTOR] Admin class destructor called" << endl;
    cout << "             -> Admin destroyed: " << name << endl;
}

// Unique functionality - manage system tasks
void Admin::manageSystem(string task) const {
    cout << ">> Admin " << name << " is performing: " << task << endl;
}

// Display complete admin information
void Admin::displayAdminInfo() const {
    cout << "+----------------------------------+" << endl;
    cout << "|       ADMIN INFORMATION          |" << endl;
    cout << "+----------------------------------+" << endl;
    displayInfo();  // Call base class function
    cout << "   Role: " << role << endl;
    cout << "+----------------------------------+" << endl;
}

// Getter
string Admin::getRole() const { return role; }