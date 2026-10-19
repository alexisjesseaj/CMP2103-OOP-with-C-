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
    gs.setStudent("2500708783", "Computer and Communications Engineering");
    gs.setGraduate("Runtime Polymorphism in C++", "Mr. Kakaire Steven");

    cout << "\nAfter updates:\n";
    gs.displayGraduate();

    return 0;
}