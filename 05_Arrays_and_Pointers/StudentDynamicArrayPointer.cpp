#include <iostream>
#include <string>
using namespace std;

// Structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Class for Student
class Student {
private:
    string name;
    int rollNumber;
    Date dob;

public:
    Student() {
        name = "";
        rollNumber = 0;
        dob = {1, 1, 2000}; // default date
    }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter date of birth (day month year): ";
        cin >> dob.day >> dob.month >> dob.year;
    }

    void display() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber
             << ", DOB: " << dob.day << "/" << dob.month << "/" << dob.year << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // Dynamically allocate array of Student objects
    Student* students = new Student[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
    }

    // Display all students
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    // Free dynamically allocated memory
    delete[] students;

    return 0;
}

