#include <iostream>
using namespace std;

// ----------- Base Class -----------
class Vehicle {
public:
    string brand;
    void getBrand() {
        cout << "Enter car brand: ";
        cin >> brand;
    }
};

// ----------- Simple Inheritance -----------
class Engine : public Vehicle {
public:
    int power;
    void getPower() {
        cout << "Enter engine power (HP): ";
        cin >> power;
    }
};

// ----------- Multilevel Inheritance -----------
class CarType : public Engine {
public:
    string type;
    void getType() {
        cout << "Enter car type (SUV/Sedan/Hatchback): ";
        cin >> type;
    }
};

// ----------- Multiple Inheritance -----------
class Wheels {
public:
    int wheels;
    void getWheels() {
        cout << "Enter number of wheels: ";
        cin >> wheels;
    }
};

class Color {
public:
    string color;
    void getColor() {
        cout << "Enter car color: ";
        cin >> color;
    }
};

// ----------- Hybrid Inheritance -----------
class Car : public CarType, public Wheels, public Color {
public:
    void display() {
        cout << "\n----- Car Details -----\n";
        cout << "Brand: " << brand << endl;   // from Vehicle
        cout << "Engine Power: " << power << " HP" << endl; // from Engine
        cout << "Type: " << type << endl;     // from CarType
        cout << "Wheels: " << wheels << endl; // from Wheels
        cout << "Color: " << color << endl;   // from Color
    }
};

int main() {
    Car myCar;

    myCar.getBrand();  // Vehicle
    myCar.getPower();  // Engine
    myCar.getType();   // CarType
    myCar.getWheels(); // Wheels
    myCar.getColor();  // Color

    myCar.display();

    return 0;
}
