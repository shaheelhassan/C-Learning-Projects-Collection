#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    int* p1 = &a;
    int* p2 = &b;

    cout << "Before swapping values:" << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    // Swap the values
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "After swapping values:" << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}

