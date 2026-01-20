#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Create objects dynamically
    Student* s1 = new Student("Alice", 20);
    Student* s2 = new Student("Bob", 25);

    cout << "\nBefore swapping pointers:" << endl;
    s1->display();
    s2->display();

    // Swap the pointers
    Student* temp = s1;
    s1 = s2;
    s2 = temp;

    cout << "\nAfter swapping pointers:" << endl;
    s1->display();
    s2->display();

    // Free memory
    delete s1;
    delete s2;

    return 0;
}

