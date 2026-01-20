#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 1. Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called" << endl;
    }

    // 2. Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called" << endl;
    }

    // 3. Copy constructor
    Student(const Student &s) {
    	
        name = s.name;
        age = s.age;
        cout << "Copy constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Using default constructor
    Student s1;
    s1.display();

    // Using parameterized constructor
    Student s2("Alice", 20);
    s2.display();

    // Using copy constructor
    Student s3 = s2;
    s3.display();

    return 0;
}

