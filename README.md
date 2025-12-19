# Smart University Management System
## OOP Assignment 3 - Hierarchical Inheritance & Object Lifecycle Management

**Course:** Object Oriented Programming (CP223-F25-BS-AI-F24-AC2)  
**Student:** Muhammad Sarmad  
**Registration:** L1F24BSAI0059  
**Section:** AC-2  
**Institution:** University of Central Punjab, Lahore, Pakistan

---

## 📋 Project Overview

This project implements a comprehensive **Smart University Management System** demonstrating advanced Object-Oriented Programming concepts through hierarchical inheritance in C++. The system models real-world university user types with proper constructor/destructor chaining and polymorphic behavior.

### 🎯 Key Features

- ✅ **Hierarchical Inheritance** - User base class with Student, Teacher, and Admin derived classes
- ✅ **Constructor Chaining** - Visual demonstration of Base → Derived initialization
- ✅ **Destructor Chaining** - Clear visualization of Derived → Base cleanup
- ✅ **Virtual Functions & Polymorphism** - Runtime polymorphism with base class pointers
- ✅ **Method Overriding** - Specialized displayInfo() in each derived class
- ✅ **Access Specifiers** - Strategic use of public, protected, and private members
- ✅ **Professional Architecture** - Multi-file structure following industry standards

---

## 🏗️ Project Structure

```
Assignment3_SmartUniversity/
├── User.h              # Base class declaration
├── User.cpp            # Base class implementation
├── Student.h           # Student derived class declaration
├── Student.cpp         # Student class implementation
├── Teacher.h           # Teacher derived class declaration
├── Teacher.cpp         # Teacher class implementation
├── Admin.h             # Admin derived class declaration
├── Admin.cpp           # Admin class implementation
├── main.cpp            # Driver program with demonstrations
└── README.md           # This file
```

---

## 🎓 Class Hierarchy

```
                    User (Base Class)
                    ├── name: string
                    ├── id: string
                    ├── login()
                    ├── logout()
                    └── displayInfo()
                           ↓
        ┌──────────────────┼──────────────────┐
        │                  │                  │
    Student            Teacher             Admin
    ├── gpa           ├── department      ├── accessLevel
    ├── courses       ├── coursesTaught   ├── managedSystems
    ├── registerCourse() ├── addCourse()     ├── manageSystem()
    └── displayInfo()  ├── uploadMarks()   ├── generateReport()
                       └── displayInfo()   └── displayInfo()
```

---

## 🚀 Compilation & Execution

### Prerequisites
- C++ compiler with C++11 support (g++, clang++, etc.)
- Standard Template Library (STL)

### Compile

```bash
g++ -std=c++11 -o SmartUniversitySystem User.cpp Student.cpp Teacher.cpp Admin.cpp main.cpp
```

### Run

```bash
./SmartUniversitySystem
```

---

## 💡 OOP Concepts Demonstrated

### 1. Hierarchical Inheritance
```cpp
class User { /* Base class */ };
class Student : public User { /* Derived class */ };
class Teacher : public User { /* Derived class */ };
class Admin : public User { /* Derived class */ };
```

### 2. Constructor Chaining
When creating derived objects, constructors execute in order:
- **First:** User (base) constructor
- **Then:** Derived class (Student/Teacher/Admin) constructor

### 3. Destructor Chaining
When destroying derived objects, destructors execute in reverse order:
- **First:** Derived class (Student/Teacher/Admin) destructor
- **Then:** User (base) destructor

### 4. Virtual Functions & Polymorphism
```cpp
class User {
    virtual void displayInfo() const;  // Virtual function
    virtual ~User();                    // Virtual destructor
};

// Runtime polymorphism
User* user = new Student(...);
user->displayInfo();  // Calls Student::displayInfo()
```

### 5. Access Specifiers
- **Protected members** (name, id) - Accessible to derived classes
- **Public methods** - Interface for user interaction
- **Private members** - Class-specific implementation details

---

## 📊 Program Output

The program provides comprehensive demonstrations of:

1. **Constructor Chaining** - Visual display showing base-to-derived construction
2. **Student Operations** - Course registration and information display
3. **Teacher Operations** - Course management and marks uploading
4. **Admin Operations** - System management and report generation
5. **Polymorphism** - Base class pointers calling derived class methods
6. **Destructor Chaining** - Visual display showing derived-to-base destruction

---

## 📝 Code Highlights

### Protected Base Members
```cpp
class User {
protected:
    string name;  // Accessible to derived classes
    string id;
public:
    void login();   // Common behavior
    void logout();
};
```

### Derived Class Extension
```cpp
class Student : public User {
private:
    vector<string> registeredCourses;  // Student-specific
    double gpa;
public:
    void registerCourse(string courseName);
    void displayInfo() const override;  // Method overriding
};
```

### Polymorphic Behavior
```cpp
User* users[3];
users[0] = new Student("Ali", "S001", 3.85);
users[1] = new Teacher("Dr. Sarah", "T001", "CS");
users[2] = new Admin("Hassan", "A001", "Super");

for(int i = 0; i < 3; i++) {
    users[i]->displayInfo();  // Polymorphism
    delete users[i];          // Virtual destructor ensures proper cleanup
}
```

---

## 🎯 Assignment Requirements Met

✅ Base class User with common attributes (name, id)  
✅ Common behaviors (login, logout)  
✅ Three derived classes (Student, Teacher, Admin)  
✅ Unique methods for each derived class  
✅ Constructor chaining demonstration  
✅ Destructor chaining demonstration  
✅ Display messages for constructor/destructor calls  
✅ Proper use of access specifiers  
✅ Object creation for each derived class  
✅ Professional multi-file structure  
✅ Comprehensive documentation  

---

## 📚 Learning Outcomes

Through this assignment, I demonstrated understanding of:

1. **Inheritance hierarchies** and IS-A relationships
2. **Constructor/destructor execution order** in inheritance
3. **Virtual functions** and runtime polymorphism
4. **Method overriding** for specialized behavior
5. **Access control** with public, protected, private
6. **Professional code organization** and documentation
7. **Memory management** in object-oriented systems

---

## 👨‍💻 Author

**Muhammad Sarmad**  
L1F24BSAI0059  
BS Artificial Intelligence  
University of Central Punjab

---

## 📄 License

This project is created for educational purposes as part of the Object-Oriented Programming course at University of Central Punjab.

---

## 🙏 Acknowledgments

- **Instructor:** Ms. Sadia Inam ul Haq
- **Course:** Object Oriented Programming (CP223-F25-BS-AI-F24-AC2)
- **Institution:** University of Central Punjab, Lahore, Pakistan

---

**Last Updated:** December 19, 2025
