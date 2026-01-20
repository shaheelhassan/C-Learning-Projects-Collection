#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
===========================================================
ABSTRACT BASE CLASS : Person
-----------------------------------------------------------
Definition:
An abstract class contains one or more pure virtual
functions and acts as a blueprint for derived classes.
===========================================================
*/
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    /*
    PURE VIRTUAL FUNCTION
    Forces every derived class to implement its own
    version of displaying information.
    */
    virtual void display() const = 0;

    /*
    PURE VIRTUAL FUNCTION
    Used to calculate performance (marks, salary, etc.).
    */
    virtual float getPerformance() const = 0;

    /*
    Virtual Destructor
    Ensures derived class destructors are called properly.
    */
    virtual ~Person() {}
};

/*
===========================================================
INTERFACE CLASS : Identifiable
-----------------------------------------------------------
Definition:
An interface in C++ is implemented using a class
that contains only pure virtual functions.
===========================================================
*/
class Identifiable {
public:
    virtual int getID() const = 0;
};

/*
===========================================================
DERIVED CLASS : Student
-----------------------------------------------------------
Represents a student entity in the system.
===========================================================
*/
class Student : public Person, public Identifiable {
private:
    int rollNo;
    float marks[5];
    static int studentCount; // Static member

public:
    /*
    Constructor increments static student count.
    */
    Student(string n, int a, int r, float m[])
        : Person(n, a), rollNo(r) {
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
        studentCount++;
    }

    /*
    Destructor decreases student count.
    */
    ~Student() {
        studentCount--;
    }

    /*
    Overriding display function
    */
    void display() const {
        cout << "\nStudent Name : " << name;
        cout << "\nAge          : " << age;
        cout << "\nRoll No      : " << rollNo;
        cout << "\nMarks        : ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
    }

    /*
    Overriding performance calculation
    */
    float getPerformance() const {
        float sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        return sum / 5;
    }

    /*
    Implementing interface method
    */
    int getID() const {
        return rollNo;
    }

    /*
    Static Function
    Returns total number of students.
    */
    static int getStudentCount() {
        return studentCount;
    }

    /*
    Friend Function
    Allows access to private members.
    */
    friend void compareStudents(const Student&, const Student&);
};

int Student::studentCount = 0;

/*
===========================================================
DERIVED CLASS : Teacher
-----------------------------------------------------------
Demonstrates polymorphism with another derived class.
===========================================================
*/
class Teacher : public Person, public Identifiable {
private:
    int empID;
    float salary;

public:
    Teacher(string n, int a, int id, float s)
        : Person(n, a), empID(id), salary(s) {}

    void display() const {
        cout << "\nTeacher Name : " << name;
        cout << "\nAge          : " << age;
        cout << "\nEmployee ID  : " << empID;
        cout << "\nSalary       : " << salary << endl;
    }

    float getPerformance() const {
        return salary; // Salary treated as performance metric
    }

    int getID() const {
        return empID;
    }
};

/*
===========================================================
FRIEND FUNCTION
-----------------------------------------------------------
Compares two students based on performance.
===========================================================
*/
void compareStudents(const Student& s1, const Student& s2) {
    cout << "\n--- Student Comparison ---\n";
    if (s1.getPerformance() > s2.getPerformance())
        cout << s1.name << " is performing better.\n";
    else
        cout << s2.name << " is performing better.\n";
}

/*
===========================================================
UTILITY FUNCTIONS
===========================================================
*/
void showMenu() {
    cout << "\n========= MENU =========";
    cout << "\n1. Add Student";
    cout << "\n2. Display All";
    cout << "\n3. Show Student Count";
    cout << "\n4. Exit";
    cout << "\n========================";
    cout << "\nEnter choice: ";
}

/*
===========================================================
MAIN FUNCTION
===========================================================
*/
int main() {

    Person* database[10];  // Polymorphic array
    int count = 0;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            int age, roll;
            float marks[5];

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter roll no: ";
            cin >> roll;
            cout << "Enter 5 marks: ";
            for (int i = 0; i < 5; i++)
                cin >> marks[i];

            database[count++] = new Student(name, age, roll, marks);
            cout << "Student added successfully!\n";
            break;
        }

        case 2:
            for (int i = 0; i < count; i++) {
                database[i]->display();
                cout << "Performance: "
                     << fixed << setprecision(2)
                     << database[i]->getPerformance() << endl;
            }
            break;

        case 3:
            cout << "Total Students: "
                 << Student::getStudentCount() << endl;
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    /*
    Memory cleanup
    */
    for (int i = 0; i < count; i++)
        delete database[i];

    return 0;
}

