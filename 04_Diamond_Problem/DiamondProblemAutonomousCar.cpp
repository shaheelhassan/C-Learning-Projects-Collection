#include <iostream>
using namespace std;

/*
    Top-Level Base Class
*/
class Machine {
protected:
    int powerRating;   // in HP

public:
    Machine(int power) {
        powerRating = power;
        cout << "Machine constructor called" << endl;
    }

    virtual void showPower() {
        cout << "Power Rating: " << powerRating << " HP" << endl;
    }

    virtual ~Machine() {
        cout << "Machine destructor called" << endl;
    }
};

/*
    Vehicle class derived from Machine
*/
class Vehicle : virtual public Machine {
protected:
    int wheels;
    int maxSpeed;

public:
    Vehicle(int power, int w, int speed)
        : Machine(power) {
        wheels = w;
        maxSpeed = speed;
        cout << "Vehicle constructor called" << endl;
    }

    virtual void showSpecs() {
        cout << "Wheels: " << wheels << endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

/*
    First Derived Class
*/
class LandVehicle : virtual public Vehicle {
protected:
    string terrainType;

public:
    LandVehicle(int power, int w, int speed, string terrain)
        : Machine(power), Vehicle(power, w, speed) {
        terrainType = terrain;
        cout << "LandVehicle constructor called" << endl;
    }

    void showTerrain() {
        cout << "Terrain Type: " << terrainType << endl;
    }

    ~LandVehicle() {
        cout << "LandVehicle destructor called" << endl;
    }
};

/*
    Second Derived Class
*/
class SmartVehicle : virtual public Vehicle {
protected:
    bool hasAI;

public:
    SmartVehicle(int power, int w, int speed, bool ai)
        : Machine(power), Vehicle(power, w, speed) {
        hasAI = ai;
        cout << "SmartVehicle constructor called" << endl;
    }

    virtual void showAI() {
        cout << "AI Enabled: " << (hasAI ? "Yes" : "No") << endl;
    }

    ~SmartVehicle() {
        cout << "SmartVehicle destructor called" << endl;
    }
};

/*
    Final Derived Class
*/
class AutonomousCar : public LandVehicle, public SmartVehicle {
private:
    int autonomyLevel;

public:
    AutonomousCar(int power, int w, int speed,
                  string terrain, bool ai, int level)
        : Machine(power),
          Vehicle(power, w, speed),
          LandVehicle(power, w, speed, terrain),
          SmartVehicle(power, w, speed, ai) {

        autonomyLevel = level;
        cout << "AutonomousCar constructor called" << endl;
    }

    // Overriding virtual functions
    void showPower() override {
        cout << "Autonomous Car Power: "
             << powerRating << " HP" << endl;
    }

    void showSpecs() override {
        cout << "\n--- Autonomous Car Specs ---" << endl;
        Vehicle::showSpecs();
        showTerrain();
        showAI();
        cout << "Autonomy Level: " << autonomyLevel << endl;
    }

    ~AutonomousCar() {
        cout << "AutonomousCar destructor called" << endl;
    }
};

/*
    Main Function
*/
int main() {

    // Base class pointer
    Machine* machinePtr =
        new AutonomousCar(300, 4, 220, "Urban", true, 5);

    cout << endl;

    // Polymorphic behavior
    machinePtr->showPower();

    // Downcasting
    Vehicle* vehiclePtr =
        dynamic_cast<Vehicle*>(machinePtr);

    if (vehiclePtr != nullptr) {
        vehiclePtr->showSpecs();
    }

    cout << endl;

    delete machinePtr;   // Proper cleanup
    return 0;
}

