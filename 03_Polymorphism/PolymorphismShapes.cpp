#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function
    virtual void area() {
        cout << "Area of shape not defined." << endl;
    }

    // Virtual destructor (good practice)
    virtual ~Shape() {}
};

// Derived class 1
class Rectangle : public Shape {
private:
    int length, width;

public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Override base class function
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

// Derived class 2
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    // Override base class function
    void area() override {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    // Base class pointer
    Shape* shape1;
    Shape* shape2;

    // Creating derived class objects
    Rectangle rect(10, 5);
    Circle cir(7);

    // Pointing base class pointers to derived objects
    shape1 = &rect;
    shape2 = &cir;

    // Runtime polymorphism
    shape1->area();   // Calls Rectangle's area()
    shape2->area();   // Calls Circle's area()

    return 0;
}

