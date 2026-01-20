#include <iostream>
using namespace std;

class Base1 {
public:
    int a;
    void getA() {
        cout << "Enter value for a: ";
        cin >> a;
    }
};

class Base2 {
public:
    int b;
    void getB() {
        cout << "Enter value for b: ";
        cin >> b;
    }
};

class Derived : public Base2 {
public:
    void display() {
        cout << "a = " << ", b = " << b << endl;
    }
};

int main() {
    Derived obj;
    obj.getB();
    obj.display();
    return 0;
}
