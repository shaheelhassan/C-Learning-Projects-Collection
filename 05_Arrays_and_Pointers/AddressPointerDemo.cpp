#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int *ptr = &num; // pointer storing address of num

    cout << "Value of num using pointer: " << *ptr << endl;
    cout << "Address of num: " << ptr << endl;

    // Modify value using pointer
    *ptr = *ptr + 10;
    cout << "New value of num after adding 10 through pointer: " << num << endl;

    return 0;
}
