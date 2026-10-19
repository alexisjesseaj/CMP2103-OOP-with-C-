# 1. Chained Inheritance

## Real-world Example
A simple educational hierarchy:

`Person` → `Student` → `GraduateStudent`

- `Person` holds basic personal data  
- `Student` adds academic identity  
- `GraduateStudent` adds research-specific information  

## C++ Program

```cpp
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Intermediate derived class
class Student : public Person {
protected:
    string studentID;
    string course;

public:
    Student(string n = "", int a = 0, string id = "", string c = "")
        : Person(n, a), studentID(id), course(c) {}

    void setStudent(string id, string c) {
        studentID = id;
        course = c;
    }

    void displayStudent() const {
        displayPerson();                 // Inherited member function
        cout << "Student ID: " << studentID
             << ", Course: " << course << endl;
    }
};

// Most derived class (end of the chain)
class GraduateStudent : public Student {
private:
    string thesisTitle;
    string supervisor;

public:
    GraduateStudent(string n = "", int a = 0,
                    string id = "", string c = "",
                    string thesis = "", string sup = "")
        : Student(n, a, id, c), thesisTitle(thesis), supervisor(sup) {}

    void setGraduate(string thesis, string sup) {
        thesisTitle = thesis;
        supervisor = sup;
    }

    void displayGraduate() const {
        displayStudent();                // Inherited from Student (which itself uses Person)
        cout << "Thesis: " << thesisTitle
             << ", Supervisor: " << supervisor << endl;
    }
};

int main() {
    cout << "=== Multilevel Inheritance Demo ===\n\n";

    // Create an object of the most derived class
    GraduateStudent gs("Sserunjogi Jesse Ssemakula", 23, "2500708783", "Computer and Communications Engineering",
                       "Efficient Multilevel Inheritance Patterns", "Mr. Kakaire Steven");

    cout << "Calling displayGraduate() on GraduateStudent object:\n";
    gs.displayGraduate();

    cout << "\n--- Demonstrating inherited members ---\n";
    // Direct access to inherited public functions
    gs.displayPerson();      // from Person
    gs.displayStudent();     // from Student

    // Modify base-class data through intermediate class
    gs.setPerson("Sserunjogi Jesse Ssemakula", 24);
    gs.setStudent("2500708783", "Comuter and Communications Engineering");
    gs.setGraduate("Runtime Polymorphism in C++", "Mr. Kakaire Steven");

    cout << "\nAfter updates:\n";
    gs.displayGraduate();

    return 0;
}
```

## Expected Output

```
=== Multilevel Inheritance Demo ===

Calling displayGraduate() on GraduateStudent object:
Name: Sserunjogi Jesse Ssemakula, Age: 23
Student ID: 2500708783, Course: Computer and Communications Engineering
Thesis: Efficient Multilevel Inheritance Patterns, Supervisor: Mr. Kakaire Steven

--- Demonstrating inherited members ---
Name: Sserunjogi Jesse Ssemakula, Age: 24
Name: Sserunjogi Jesse Ssemakula, Age: 24
Student ID: 2500708783, Course: Computer and Communications Engineering

After updates:
Name: Sserunjogi Jesse Ssemakula, Age: 24
Student ID: GS2026-099, Course: Comuter and Communications Engineering
Thesis: Runtime Polymorphism in C++, Supervisor: Mr. Kakaire Steven
```

## Hand-drawn Style Illustration

```
          +-------------------+
          |     Person        |   ← Base class
          |-------------------|
          | name, age         |
          | setPerson()       |
          | displayPerson()   |
          +---------+---------+
                    |
                    | inherits
                    v
          +-------------------+
          |     Student       |   ← Intermediate class
          |-------------------|
          | studentID, course |
          | setStudent()      |
          | displayStudent()  |   (calls displayPerson)
          +---------+---------+
                    |
                    | inherits
                    v
          +-------------------+
          | GraduateStudent   |   ← Most derived class
          |-------------------|
          | thesisTitle       |
          | supervisor        |
          | setGraduate()     |
          | displayGraduate() |   (calls displayStudent → displayPerson)
          +-------------------+
```

**Key Point:**  
`GraduateStudent` automatically receives all public/protected members of both `Student` and `Person` without rewriting them.