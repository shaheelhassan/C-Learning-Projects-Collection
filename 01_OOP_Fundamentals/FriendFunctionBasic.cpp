#include <iostream>
using namespace std;

class Number {
private:
    int x;

public:
    Number(int a) {     // constructor
        x = a;
    }

    // friend function declaration
    friend void show(Number obj);
};

// friend function definition
void show(Number obj) {
    cout << "Value of x = " << obj.x;
}

int main() {
    Number n(10);
    show(n);
    return 0;
}

