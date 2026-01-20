#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes sound" << endl;
    }
};

class Mammal : public Animal {
};

class Bird : public Animal {
};

class Bat : public Mammal, public Bird {
};

int main() {
    Bat b;
    // b.sound();  // ? Ambiguous
    return 0;
}

