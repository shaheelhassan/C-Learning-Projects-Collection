#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int marks;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n]; // Array of objects

    // Input data for each student
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        students[i].input();
    }

    // Display student data
    cout << "\nStudent Details:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    return 0;
}
