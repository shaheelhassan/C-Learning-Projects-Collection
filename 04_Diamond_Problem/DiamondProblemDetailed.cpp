#include <iostream>
using namespace std;

/*
    Base Class
*/
class Vehicle {
public:
    int maxSpeed;

    Vehicle(int speed) {
        maxSpeed = speed;
        cout << "Vehicle constructor called" << endl;
    }

    void showSpeed() {
        cout << "Maximum Speed: " << maxSpeed << " km/h" << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

/*
    Car class derived from Vehicle
*/
class Car : virtual public Vehicle {
public:
    string brand;
    string color;
    double price;

    Car(int speed, string b, string c, double p)
        : Vehicle(speed) {
        brand = b;
        color = c;
        price = p;
        cout << "Car constructor called" << endl;
    }

    void showCarDetails() {
        cout << "Brand : " << brand << endl;
        cout << "Color : " << color << endl;
        cout << "Price : $" << price << endl;
    }

    virtual ~Car() {
        cout << "Car destructor called" << endl;
    }
};

/*
    ElectricCar derived from Car
*/
class ElectricCar : virtual public Car {
public:
    int batteryCapacity;

    ElectricCar(int speed, string b, string c, double p, int battery)
        : Vehicle(speed), Car(speed, b, c, p) {
        batteryCapacity = battery;
        cout << "ElectricCar constructor called" << endl;
    }

    void showBattery() {
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    ~ElectricCar() {
        cout << "ElectricCar destructor called" << endl;
    }
};

/*
    PetrolCar derived from Car
*/
class PetrolCar : virtual public Car {
public:
    int fuelTank;

    PetrolCar(int speed, string b, string c, double p, int tank)
        : Vehicle(speed), Car(speed, b, c, p) {
        fuelTank = tank;
        cout << "PetrolCar constructor called" << endl;
    }

    void showFuelTank() {
        cout << "Fuel Tank Capacity: " << fuelTank << " liters" << endl;
    }

    ~PetrolCar() {
        cout << "PetrolCar destructor called" << endl;
    }
};

/*
    HybridCar derived from ElectricCar and PetrolCar
*/
class HybridCar : public ElectricCar, public PetrolCar {
public:
    HybridCar(int speed, string b, string c, double p,
              int battery, int tank)
        : Vehicle(speed),
          Car(speed, b, c, p),
          ElectricCar(speed, b, c, p, battery),
          PetrolCar(speed, b, c, p, tank) {

        cout << "HybridCar constructor called" << endl;
    }

    void showHybridDetails() {
        cout << "\n--- Hybrid Car Details ---" << endl;
        showCarDetails();
        showSpeed();
        showBattery();
        showFuelTank();
    }

    ~HybridCar() {
        cout << "HybridCar destructor called" << endl;
    }
};

/*
    Main Function
*/
int main() {

    // Base class pointer (Vehicle) pointing to HybridCar object
    Vehicle* vehiclePtr =
        new HybridCar(180, "Toyota", "White", 32000, 40, 45);

    cout << endl;



   

    cout << endl;

    delete vehiclePtr;   // Proper cleanup due to virtual destructor
    return 0;
}

