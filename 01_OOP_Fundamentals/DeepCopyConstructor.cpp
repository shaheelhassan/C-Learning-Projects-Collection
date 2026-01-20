#include <iostream>
using namespace std;

class Deep {
private:
    int* data;
public:
    Deep(int value) {
        data = new int;
        *data = value;    /// permition to change values stored in it
    }

    // Custom copy constructor (deep copy)
    Deep(const Deep &obj) {
        data = new int;       // allocate new memory
        *data = *obj.data;    // copy the value
    }

    void setValue(int value) {
        *data = value;
    }

    void showData() {
        cout << "Data: " << *data << endl;
    }

    ~Deep() {
        delete data;
    }
};

int main() {
    Deep obj1(10);
    Deep obj2 = obj1; // deep copy

    cout << "Before changing obj2:" << endl;
    obj1.showData();
    obj2.showData();

    obj2.setValue(20);

    cout << "After changing obj2:" << endl;
    obj1.showData(); // not affected
    obj2.showData();

    return 0;
}

