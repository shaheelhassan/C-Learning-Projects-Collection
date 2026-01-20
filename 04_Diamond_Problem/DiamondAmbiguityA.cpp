#include <iostream>
using namespace std;

// Base class
class A {
public:
    int x;

    A() {
        x = 10;
    }
};

// Derived class B
class B : public A {
};

// Derived class C
class C : public A {
};

// Derived class D (inherits from B and C)
class D : public B, public C {
};

int main() {
    D obj;

    // obj.x = 20;   ? ERROR: Ambiguous
    cout << obj.B::x << endl; // Works
    cout << obj.C::x << endl; // Works

    return 0;
}

