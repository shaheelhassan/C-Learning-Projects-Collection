#include <iostream>
using namespace std;

class Shallow {
private:
    int* data;
public:
    Shallow(int value) {
        data = new int;
        *data = value;
    }

    // Default copy constructor (shallow copy)
    Shallow(const Shallow &obj) {
        data = obj.data; // just copies pointer
    }

    void setValue(int value) {
        *data = value;
    }

    void showData() {
        cout << "Data: " << *data << endl;
    }

    ~Shallow() {
        delete data;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1; // shallow copy

    cout << "Before changing obj2:" << endl;
    obj1.showData();
    obj2.showData();

    obj2.setValue(20);

    cout << "After changing obj2:" << endl;
    obj1.showData(); // affected because of shallow copy
    obj2.showData();

    return 0;
}

