#include <iostream>
using namespace std;

class Vehicle {
public:
    void display() {
        cout << "This is a vehicle" << endl;
    }
};

class Car : virtual public Vehicle {
};

class Bike : virtual public Vehicle {
};

class HybridVehicle : public Car, public Bike {
};

int main() {
    HybridVehicle hv;
    hv.display();   // ? No ambiguity
    return 0;
}

