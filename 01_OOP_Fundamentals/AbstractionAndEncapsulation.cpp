#include <iostream>
#include <string>
using namespace std;

// ===============================
// Class: Student
// ===============================
class Student {
private:
    string name;  // Encapsulation: private data
    int marks;    // Encapsulation: private data

public:
    // Constructor
    Student(string n, int m) : name(n), marks(m) {}

    // Member Function: Display Student Info
    void displayStudent() {
        cout << "Student Name: " << name << ", Marks: " << marks 
             << ", Grade: " << calculateGrade() << endl;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Getter for marks
    int getMarks() {
        return marks;
    }

    // Setter for marks (Abstraction)
    void setMarks(int m) {
        if (m >= 0 && m <= 100)
            marks = m;
        else
            cout << "Invalid marks!" << endl;
    }

    // Member function to calculate grade (Abstraction)
    char calculateGrade() {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 50) return 'D';
        else return 'F';
    }

    // Friend function declaration
    friend void congratulate(Student &s);

    // Friend class declaration
    friend class Professor;
};

// ===============================
// Friend Function
// ===============================
void congratulate(Student &s) {
    if (s.marks >= 90)
        cout << "Congratulations " << s.name << "! Excellent marks!" << endl;
    else
        cout << "Good job " << s.name << ". Keep improving!" << endl;
}

// ===============================
// Class: Teacher
// ===============================
class Teacher {
public:
    // Member function to update marks
    void updateMarks(Student &s, int newMarks) {
        s.setMarks(newMarks); // Use setter (Encapsulation)
        cout << "Teacher updated marks for " << s.getName() << endl;
    }
};

// ===============================
// Class: Professor
// ===============================
class Professor {
public:
    // Friend class accessing private data
    void showStudentMarks(Student &s) {
        cout << "Professor accessing private data: " 
             << s.name << " has marks " << s.marks 
             << " and grade " << s.calculateGrade() << endl;
    }

    // Using friend function to praise student
    void praiseStudent(Student &s) {
        congratulate(s);
    }
};

// ===============================
// Main Function
// ===============================
int main() {
    // Creating multiple students
    Student s1("Alice", 92);
    Student s2("Bob", 78);
    Student s3("Charlie", 55);

    // Display initial data
    cout << "Initial Student Data:" << endl;
    s1.displayStudent();
    s2.displayStudent();
    s3.displayStudent();
    cout << "-------------------------------" << endl;

    // Friend function usage
    congratulate(s1);
    congratulate(s3);
    cout << "-------------------------------" << endl;

    // Teacher updating marks
    Teacher t;
    t.updateMarks(s2, 85);
    t.updateMarks(s3, 65);
    cout << "After Teacher Updates:" << endl;
    s2.displayStudent();
    s3.displayStudent();
    cout << "-------------------------------" << endl;

    // Professor accessing and praising students
    Professor p;
    p.showStudentMarks(s1);
    p.showStudentMarks(s2);
    p.showStudentMarks(s3);
    cout << "-------------------------------" << endl;

    p.praiseStudent(s1);
    p.praiseStudent(s3);

    return 0;
}

