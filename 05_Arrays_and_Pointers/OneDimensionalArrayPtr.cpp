#include <iostream>
using namespace std;

class Numbers {
private:
    int arr[5];      // 1D array
    int *ptr;        // pointer

public:
    Numbers() {
        // initialize array
        for (int i = 0; i < 5; i++) {
            arr[i] = i+1;
        }

        // pointer points to array
        ptr = arr;
    }

    void display() {
        cout << "Using array:\n";
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n\nUsing pointer:\n";
        for (int i = 0; i < 5; i++) {
            cout << *(ptr + i) << " ";
        }
    }
};

int main() {
    Numbers obj;
    obj.display();
    return 0;
}

