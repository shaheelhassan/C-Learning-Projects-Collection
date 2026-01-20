#include <iostream>
#include <cstring>
using namespace std;

/* =======================
   BASE CLASS
======================= */
class Vehicle {
protected:
    char* brand;

public:
    // Constructor
    Vehicle(const char* b = "Unknown") {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        cout << "Vehicle constructor called\n";
    }

    // Deep Copy Constructor
    Vehicle(const Vehicle& v) {
        brand = new char[strlen(v.brand) + 1];
        strcpy(brand, v.brand);
        cout << "Vehicle deep copy constructor called\n";
    }

    // Virtual function
    virtual void show() {
        cout << "Vehicle Brand: " << brand << endl;
    }

    // Virtual destructor (CRUCIAL)
    virtual ~Vehicle() {
        delete[] brand;
        cout << "Vehicle destructor called\n";
    }
};

/* =======================
   DERIVED CLASS 1
======================= */
class Car : public Vehicle {
protected:
    int speed;

public:
    // Constructor
    Car(const char* b, int s) : Vehicle(b) {
        speed = s;
        cout << "Car constructor called\n";
    }

    // Copy Constructor (calls base copy)
    Car(const Car& c) : Vehicle(c) {
        speed = c.speed;
        cout << "Car copy constructor called\n";
    }

    // Overriding virtual function
    void show() override {
        cout << "Car Brand: " << brand
             << ", Speed: " << speed << " km/h" << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car destructor called\n";
    }
};

/* =======================
   DERIVED CLASS 2
======================= */
class ElectricCar : public Car {
private:
    int battery;

public:
    // Constructor
    ElectricCar(const char* b, int s, int bat)
        : Car(b, s) {
        battery = bat;
        cout << "ElectricCar constructor called\n";
    }

    // Copy Constructor
    ElectricCar(const ElectricCar& e)
        : Car(e) {
        battery = e.battery;
        cout << "ElectricCar copy constructor called\n";
    }

    // Overriding again (POLYMORPHISM)
    void show() override {
        cout << "Electric Car Brand: " << brand
             << ", Speed: " << speed
             << " km/h, Battery: " << battery << "%" << endl;
    }

    // Destructor
    ~ElectricCar() {
        cout << "ElectricCar destructor called\n";
    }
};

/* =======================
   MAIN FUNCTION
======================= */
int main() {

    cout << "\n--- Creating Objects ---\n";
    Vehicle* v1 = new Car("Toyota", 180);
    Vehicle* v2 = new ElectricCar("Tesla", 250, 90);

    cout << "\n--- Polymorphic Calls ---\n";
    v1->show();   // Calls Car::show()
    v2->show();   // Calls ElectricCar::show()

    cout << "\n--- Deep Copy Demonstration ---\n";
    ElectricCar e1("BMW", 220, 80);
    ElectricCar e2 = e1;  // Deep copy

    e2.show();

    cout << "\n--- Deleting Objects ---\n";
    delete v1;   // Proper destructor chain
    delete v2;

    cout << "\n--- Program End ---\n";
    return 0;
}

