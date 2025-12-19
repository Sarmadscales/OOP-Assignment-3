/*
 * ============================================================================
 * File: main.cpp
 * Description: Driver program for Smart University Management System
 * Purpose: Demonstrates hierarchical inheritance and constructor/destructor
 *          calling order in C++
 * ============================================================================
 * Student: Muhammad Sarmad
 * Roll No: L1F24BSAI0059
 * Course: Object Oriented Programming (CP223-F25-BS-AI-F24-AC2)
 * ============================================================================
 */

#include "User.h"

// Function to print section headers
void printHeader(string title) {
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "   " << title << endl;
    cout << "==========================================================" << endl;
}

// Function to print sub-headers
void printSubHeader(string title) {
    cout << endl << "--- " << title << " ---" << endl;
}

int main() {
    // ========================================================================
    // PROGRAM HEADER
    // ========================================================================
    cout << "**********************************************************" << endl;
    cout << "*                                                        *" << endl;
    cout << "*       SMART UNIVERSITY MANAGEMENT SYSTEM               *" << endl;
    cout << "*       Hierarchical Inheritance Demonstration           *" << endl;
    cout << "*                                                        *" << endl;
    cout << "*  Student: Muhammad Sarmad | Roll No: L1F24BSAI0059     *" << endl;
    cout << "*                                                        *" << endl;
    cout << "**********************************************************" << endl;

    // ========================================================================
    // SECTION 1: DEMONSTRATING CONSTRUCTOR ORDER (Base -> Derived)
    // ========================================================================
    printHeader("SECTION 1: OBJECT CREATION & CONSTRUCTOR ORDER");
    cout << "Observation: Base class constructor is called FIRST," << endl;
    cout << "             then Derived class constructor is called." << endl;
    cout << "             Order: User() -> DerivedClass()" << endl;

    // Creating objects inside a block to control scope and observe destructors
    {
        // Creating Student object
        printSubHeader("Creating Student Object");
        Student student1("Ahmed Ali", 101, "BS Artificial Intelligence");

        // Creating Teacher object
        printSubHeader("Creating Teacher Object");
        Teacher teacher1("Dr. Sara Khan", 201, "Computer Science");

        // Creating Admin object
        printSubHeader("Creating Admin Object");
        Admin admin1("Usman Ahmad", 301, "System Administrator");

        // ====================================================================
        // SECTION 2: DISPLAYING INFORMATION
        // ====================================================================
        printHeader("SECTION 2: DISPLAYING USER INFORMATION");

        student1.displayStudentInfo();
        cout << endl;
        teacher1.displayTeacherInfo();
        cout << endl;
        admin1.displayAdminInfo();

        // ====================================================================
        // SECTION 3: DEMONSTRATING COMMON BEHAVIORS (Inherited from User)
        // ====================================================================
        printHeader("SECTION 3: COMMON BEHAVIORS (Inherited from User)");
        cout << "All derived classes inherit login() and logout() from User class." << endl;

        printSubHeader("Student Login/Logout");
        student1.login();
        student1.logout();

        printSubHeader("Teacher Login/Logout");
        teacher1.login();
        teacher1.logout();

        printSubHeader("Admin Login/Logout");
        admin1.login();
        admin1.logout();

        // ====================================================================
        // SECTION 4: DEMONSTRATING UNIQUE FUNCTIONALITIES
        // ====================================================================
        printHeader("SECTION 4: UNIQUE FUNCTIONALITIES");
        cout << "Each derived class has its own unique functionality." << endl;

        printSubHeader("Student: registerCourse()");
        student1.registerCourse("Object Oriented Programming");
        student1.registerCourse("Data Structures & Algorithms");

        printSubHeader("Teacher: uploadMarks()");
        teacher1.uploadMarks("OOP", 85);
        teacher1.uploadMarks("DSA", 90);

        printSubHeader("Admin: manageSystem()");
        admin1.manageSystem("Adding new course to database");
        admin1.manageSystem("Generating semester reports");

        // ====================================================================
        // SECTION 5: DEMONSTRATING IS-A RELATIONSHIP
        // ====================================================================
        printHeader("SECTION 5: IS-A RELATIONSHIP DEMONSTRATION");
        cout << "Hierarchical Inheritance establishes IS-A relationships:" << endl;
        cout << "  - " << student1.getName() << " IS-A User (Student inherits User)" << endl;
        cout << "  - " << teacher1.getName() << " IS-A User (Teacher inherits User)" << endl;
        cout << "  - " << admin1.getName() << " IS-A User (Admin inherits User)" << endl;

        // ====================================================================
        // SECTION 6: DEMONSTRATING DESTRUCTOR ORDER (Derived -> Base)
        // ====================================================================
        printHeader("SECTION 6: DESTRUCTOR ORDER DEMONSTRATION");
        cout << "Objects are going out of scope now..." << endl;
        cout << "Observation: Derived class destructor is called FIRST," << endl;
        cout << "             then Base class destructor is called." << endl;
        cout << "             Order: ~DerivedClass() -> ~User()" << endl;
        cout << endl;
        cout << "Also Note: Objects are destroyed in REVERSE order of creation" << endl;
        cout << "           (LIFO - Last In First Out)" << endl;
        cout << "           Creation: Student -> Teacher -> Admin" << endl;
        cout << "           Destruction: Admin -> Teacher -> Student" << endl;
        cout << endl;
        cout << "--- Destructors Being Called ---" << endl;

    } // Objects go out of scope here - destructors are called

    // ========================================================================
    // PROGRAM FOOTER
    // ========================================================================
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << "*                                                        *" << endl;
    cout << "*              PROGRAM EXECUTION COMPLETE                *" << endl;
    cout << "*                                                        *" << endl;
    cout << "*  Constructor Order: Base -> Derived (Top-Down)         *" << endl;
    cout << "*  Destructor Order: Derived -> Base (Bottom-Up)         *" << endl;
    cout << "*                                                        *" << endl;
    cout << "**********************************************************" << endl;

    return 0;
}

/*
 * ============================================================================
 * SUMMARY OF OBSERVATIONS:
 * ============================================================================
 * 
 * 1. CONSTRUCTOR CALLING ORDER (Base -> Derived):
 *    - When Student is created: User() -> Student()
 *    - When Teacher is created: User() -> Teacher()
 *    - When Admin is created: User() -> Admin()
 *    - Reason: Base class must be initialized before derived class
 * 
 * 2. DESTRUCTOR CALLING ORDER (Derived -> Base):
 *    - When Admin is destroyed: ~Admin() -> ~User()
 *    - When Teacher is destroyed: ~Teacher() -> ~User()
 *    - When Student is destroyed: ~Student() -> ~User()
 *    - Reason: Derived class cleanup before base class cleanup
 * 
 * 3. OBJECT DESTRUCTION ORDER (LIFO):
 *    - Objects are destroyed in reverse order of creation
 *    - Last created object (Admin) is first to be destroyed
 *    - First created object (Student) is last to be destroyed
 * 
 * 4. HIERARCHICAL INHERITANCE:
 *    - Single base class (User) with multiple derived classes
 *    - Each derived class inherits common attributes and behaviors
 *    - Each derived class adds its own unique functionality
 * 
 * 5. ACCESS SPECIFIERS:
 *    - Protected: name, id (accessible in derived classes)
 *    - Private: program, department, role (specific to each class)
 *    - Public: All member functions
 * 
 * ============================================================================
 */