#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int &ref = num; // reference to num

    cout << "Value of num using reference: " << ref << endl;

    // Modify value using reference
    ref = ref + 20;
    cout << "New value of num after adding 20 through reference: " << num << endl;

    return 0;
}
