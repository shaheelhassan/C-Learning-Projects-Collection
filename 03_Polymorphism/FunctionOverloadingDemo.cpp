#include <iostream>
using namespace std;

class Calculator {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two floats
    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    int x, y, z;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "Sum of two integers: " << calc.add(x, y) << endl;

    cout << "Enter three integers: ";
    cin >> x >> y >> z;
    cout << "Sum of three integers: " << calc.add(x, y, z) << endl;

    float p, q;
    cout << "Enter two float numbers: ";
    cin >> p >> q;
    cout << "Sum of two floats: " << calc.add(p, q) << endl;

    return 0;
}
