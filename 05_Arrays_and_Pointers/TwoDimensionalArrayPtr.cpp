#include <iostream>
using namespace std;

class Matrix {
private:
    int arr[2][3];     // 2D array (2 rows, 3 columns)
    int *ptr;          // pointer

public:
    Matrix() {
        // initialize 2D array
        int value = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = value++;
            }
        }

        // pointer points to first element of 2D array
        ptr = &arr[1][1];
    }

    void display() {
        cout << "Using 2D array:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nUsing pointer:\n";
        for (int i = 0; i < 6; i++) {
            cout << *(ptr + i) << " ";
        }
    }
};

int main() {
    Matrix obj;
    obj.display();
    return 0;
}

