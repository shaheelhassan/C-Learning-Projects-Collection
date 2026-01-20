#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void displayType() {
        cout << "This is a generic vehicle." << endl;
    }
};

class Car : public Vehicle {
public:
    void displayType() override { // overrides base class function
        cout << "This is a car." << endl;
    }
};

class Bike : public Vehicle {
public:
    void displayType() override {
        cout << "This is a bike." << endl;
    }
};

int main() {
    Vehicle *v;

    Car myCar;
    Bike myBike;

    v = &myCar;
    v->displayType(); // Calls Car's version

    v = &myBike;
    v->displayType(); // Calls Bike's version

    return 0;
}
