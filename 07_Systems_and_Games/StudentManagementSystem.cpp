#include <iostream>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayData() {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class
class Student : public Person {
public:
    int roll;
    float marks;

    void getStudentData() {
        getData(); // from Person
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void displayStudentData() {
        displayData(); // from Person
        cout << ", Roll: " << roll << ", Marks: " << marks << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n]; // Dynamically allocate array of objects

    // Pointer to Student
    Student *ptr;

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        ptr = &students[i]; // Pointer pointing to ith object
        ptr->getStudentData(); // accessing object using pointer
    }

    // Display data
    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < n; i++) {
        ptr = &students[i]; // Pointer pointing to ith object
        ptr->displayStudentData(); // accessing object using pointer
    }

    delete[] students; // Deallocate memory
    return 0;
}
