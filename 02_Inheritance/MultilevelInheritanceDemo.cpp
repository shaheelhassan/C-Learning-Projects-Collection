#include <iostream>
using namespace std;

class Base {
public:
    int x;
    void getData() {
        cout << "Enter a value for x: ";
        cin >> x;
    }
};

class Intermediate : public Base {
public:
    int y;
    void getY() {
        cout << "Enter a value for y: ";
        cin >> y;
    }
};

class Derived : public Intermediate {
public:
    void display() {
        cout << "x = " <<  << ", y = " << y << endl;
    }
};

int main() {
    Derived obj;
    obj.getData();
    obj.getY();
    obj.display();
    return 0;
}
