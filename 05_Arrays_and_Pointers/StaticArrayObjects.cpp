#include <iostream>
#include <string>
using namespace std;

// Define a structure for a simple Date
struct Date {
    int day;
    int month;
    int year;
};

// Define a class for Student
class Student {
private:
    string name;
    int rollNumber;
    Date dob; // Using the structure inside the class

public:
    // Constructor to initialize a student
    Student() {
        name = "";
        rollNumber = 0;
        dob = {1, 1, 2000}; // default date
    }

    // Function to input student details
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter date of birth (day month year): ";
        cin >> dob.day >> dob.month >> dob.year;
    }

    // Function to display student details
    void display() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber 
             << ", DOB: " << dob.day << "/" << dob.month << "/" << dob.year << endl;
    }
};

int main() {
    const int SIZE = 3; // static array size
    Student students[SIZE]; // static array of objects

    // Input details for all students
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
    }

    // Display all students
    cout << "\nStudent Details:\n";
    for (int i = 0; i < SIZE; i++) {
        students[i].display();
    }

    return 0;
}

