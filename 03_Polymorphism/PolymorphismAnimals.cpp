#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    // Virtual destructor (important for polymorphism)
    virtual ~Animal() {}
};

// Derived class 1
class Dog : public Animal {
public:
    // Override sound function
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    // Override sound function
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

// Derived class 3
class Cow : public Animal {
public:
    // Override sound function
    void sound() override {
        cout << "Cow moos" << endl;
    }
};

int main() {
    // Base class pointer
    Animal* animal;

    Dog dog;
    Cat cat;
    Cow cow;

    // Pointing to different derived objects
    animal = &dog;
    animal->sound();   // Calls Dog's sound()

    animal = &cat;
    animal->sound();   // Calls Cat's sound()

    animal = &cow;
    animal->sound();   // Calls Cow's sound()

    return 0;
}

