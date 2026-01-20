#include <iostream>
#include <cstring>
using namespace std;

/* =======================
   BASE CLASS
======================= */
class Person {
protected:
    int id;
    char name[50];
    int age;

public:
    Person() {
        cout << "Enter Person ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    void showPerson() {
        cout << "\n--- Person Info ---\n";
        cout << "ID   : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

/* =======================
   EMPLOYEE CLASS
======================= */
class Employee : virtual public Person {
protected:
    int empId;
    float salary;

public:
    Employee() {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void showEmployee() {
        cout << "\n--- Employee Info ---\n";
        cout << "Employee ID : " << empId << endl;
        cout << "Salary      : " << salary << endl;
    }
};

/* =======================
   STUDENT CLASS
======================= */
class Student : virtual public Person {
protected:
    int rollNo;
    char course[30];

public:
    Student() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Course: ";
        cin >> course;
    }

    void showStudent() {
        cout << "\n--- Student Info ---\n";
        cout << "Roll No : " << rollNo << endl;
        cout << "Course  : " << course << endl;
    }
};

/* =======================
   INTERN CLASS
======================= */
class Intern : public Employee, public Student {
private:
    int duration;   // months

public:
    Intern() {
        cout << "Enter Internship Duration (months): ";
        cin >> duration;
    }

    void showIntern() {
        showPerson();
        showEmployee();
        showStudent();

        cout << "\n--- Intern Info ---\n";
        cout << "Duration : " << duration << " months\n";
    }
};

/* =======================
   MAIN FUNCTION
======================= */
int main() {

    cout << "\n--- Enter Intern Details ---\n";
    Intern i1;

    cout << "\n--- Displaying Intern Details ---\n";
    i1.showIntern();

    /* ===== Pointer Demonstration ===== */
    cout << "\n--- Pointer Test ---\n";

    Person* p = &i1;     // ? Works (NO ambiguity)
    p->showPerson();

    return 0;
}

