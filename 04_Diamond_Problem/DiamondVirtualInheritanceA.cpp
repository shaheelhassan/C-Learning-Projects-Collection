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

// B virtually inherits A
class B : virtual public A {
};

// C virtually inherits A
class C : virtual public A {
};

// D inherits B and C
class D : public B, public C {
};

int main() {
    D obj;

    // No ambiguity now
    obj.x = 50;
    cout << obj.x << endl;

    return 0;
}

