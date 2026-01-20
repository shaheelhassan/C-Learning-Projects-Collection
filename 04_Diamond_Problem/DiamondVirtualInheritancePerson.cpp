#include <iostream>
using namespace std;

class Person {
public:
    void show() {
        cout << "I am a person" << endl;
    }
};

class Student : virtual public Person {
};

class Teacher : virtual public Person {
};

class Professor : public Student, public Teacher {
};

int main() {
    Professor p;
    p.show();   // ? No ambiguity
    return 0;
}

