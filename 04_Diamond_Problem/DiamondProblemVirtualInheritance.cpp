#include <iostream>
using namespace std;

/*
    Base Class
*/
class Car {
public:
    string color;

    // Constructor
    Car(string c) {
        color = c;
        cout << "Car constructor called" << endl;
    }

    // Member function
    void showColor() {
        cout << "Car color is: " << color << endl;
    }

    // Virtual destructor (good practice when using base pointers)
    virtual ~Car() {
        cout << "Car destructor called" << endl;
    }
};

/*
    First Derived Class
    Virtual inheritance prevents duplicate Car objects
*/
class Electric : virtual public Car {
public:
    Electric(string c) : Car(c) {
        cout << "Electric constructor called" << endl;
    }

    ~Electric() {
        cout << "Electric destructor called" << endl;
    }
};

/*
    Second Derived Class
    Virtual inheritance prevents duplicate Car objects
*/
class Petrol : virtual public Car {
public:
    Petrol(string c) : Car(c) {
        cout << "Petrol constructor called" << endl;
    }

    ~Petrol() {
        cout << "Petrol destructor called" << endl;
    }
};

/*
    Final Derived Class
    Inherits from both Electric and Petrol
*/
class HybridCar : public Electric, public Petrol {
public:
    HybridCar(string c)
        : Car(c), Electric(c), Petrol(c) {
        cout << "HybridCar constructor called" << endl;
    }

    ~HybridCar() {
        cout << "HybridCar destructor called" << endl;
    }
};

/*
    Main Function
*/
int main() {

    // Base class pointer pointing to derived class object
    Car* carPtr = new HybridCar("Blue");

    // Accessing base class function
    carPtr->showColor();

    // Free allocated memory
    delete carPtr;

    return 0;
}

