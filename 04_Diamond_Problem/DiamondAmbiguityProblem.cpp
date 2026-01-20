#include <iostream>
using namespace std;

class Vehicle {
public:
    void display() {
        cout << "This is a vehicle" << endl;
    }
};

class Car : public Vehicle {
};

class Bike : public Vehicle {
};

class HybridVehicle : public Car, public Bike {
};

int main() {
    HybridVehicle hv;
    // hv.display();   // ? Ambiguous
    return 0;
}

