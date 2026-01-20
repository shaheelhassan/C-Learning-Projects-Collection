#include <iostream>
using namespace std;

// Base class
class Base {
public:
    int x;
    void getX() {
        cout << "Enter value for x: ";
        cin >> x;
    }
};

// First derived class (inherits Base)
class Derived1 : public Base {
public:
    int y;
    void getY() {
        cout << "Enter value for y: ";
        cin >> y;
    }
};

// Second derived class (inherits Base)
class Derived2 : public Base {
public:
    int z;
    void getZ() {
        cout << "Enter value for z: ";
        cin >> z;
    }
};

// Hybrid derived class (inherits Derived1 and Derived2)
class Hybrid : public Derived1, public Derived2 {
public:
    void display() {
        // Need to use scope resolution because x is in both Derived1 and Derived2
        cout << "x from Derived1 = " << Derived1::x << ", y = " << y << ", z = " << z << endl;
    }
};

int main() {
    Hybrid obj;
    obj.Derived1::getX();
    obj.getY();
    obj.getZ();
    obj.display();
    return 0;
}
