#include <iostream>
using namespace std;

class Item {
public:
    string name;
    float price;

    void input() {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: ";
        cin >> price;
    }

    void display() {
        cout << name << " - $" << price << "\t";
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Dynamically allocate 2D array of Items
    Item** items = new Item*[rows];
    for (int i = 0; i < rows; i++) {
        items[i] = new Item[cols];
    }

    // Input data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "\nEnter details for item at [" << i << "][" << j << "]" << endl;
            items[i][j].input();
        }
    }

    // Display data
    cout << "\nItem Details:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            items[i][j].display();
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] items[i];
    }
    delete[] items;

    return 0;
}

