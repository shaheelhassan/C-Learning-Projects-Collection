#include <iostream>
using namespace std;

// Base class
class Base {
public:
    int x;

    void getData() {
        cout << "Enter a value for x: ";
        cin >> x;
    }
};

// Derived class
class Derived : public Base {
public:
    void display() {
        cout << "Value of x is: " << x << endl;
    }
};

int main() {
    Derived obj;  // Create object of Derived class

    obj.getData();  // Call Base class function
    obj.display();  // Call Derived class function

    return 0;
}

