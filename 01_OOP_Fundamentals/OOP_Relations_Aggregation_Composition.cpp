#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
===========================================================
COMPOSITION EXAMPLE
-----------------------------------------------------------
Student HAS-A Address (composition)
Address exists only as part of Student
===========================================================
*/
class Address {
private:
    string street;
    string city;

public:
    Address(string s = "", string c = "") : street(s), city(c) {}

    void display() const {
        cout << street << ", " << city;
    }
};

class Student {
private:
    string name;
    int rollNo;
    Address address; // Composition: Address is part of Student

public:
    Student(string n, int r, const Address& addr)
        : name(n), rollNo(r), address(addr) {}

    void display() const {
        cout << "Student: " << name << ", Roll No: " << rollNo << endl;
        cout << "Address: ";
        address.display();
        cout << endl;
    }
};

/*
===========================================================
AGGREGATION EXAMPLE
-----------------------------------------------------------
School HAS-A collection of Teachers (Aggregation)
Teachers can exist independently of School
===========================================================
*/
class Teacher {
private:
    string name;
    string subject;

public:
    Teacher(string n, string sub) : name(n), subject(sub) {}

    void display() const {
        cout << "Teacher: " << name << ", Subject: " << subject << endl;
    }
};

class School {
private:
    string schoolName;
    vector<Teacher*> teachers; // Aggregation: teachers can exist outside school

public:
    School(string n) : schoolName(n) {}

    void addTeacher(Teacher* t) {
        teachers.push_back(t);
    }

    void display() const {
        cout << "\nSchool: " << schoolName << endl;
        cout << "Teachers:\n";
        for (size_t i = 0; i < teachers.size(); i++)
            teachers[i]->display();
    }

    string getName() const {
        return schoolName;
    }
};

/*
===========================================================
ASSOCIATION EXAMPLE
-----------------------------------------------------------
TeacherAssociation knows about School without owning it
Teacher can access School info but lifetime is independent
===========================================================
*/
class TeacherAssociation {
private:
    string name;
    string subject;
    School* school; // Association: pointer to School, no ownership

public:
    TeacherAssociation(string n, string sub, School* s)
        : name(n), subject(sub), school(s) {}

    void display() const {
        cout << "\nTeacher: " << name << ", Subject: " << subject;
        if (school)
            cout << ", Associated School: " << school->getName();
        cout << endl;
    }
};

int main() {
    cout << "===== COMPOSITION =====\n";
    Address addr1("123 Main St", "New York");
    Student s1("Alice", 101, addr1);
    s1.display();

    cout << "\n===== AGGREGATION =====\n";
    Teacher t1("Mr. Smith", "Math");
    Teacher t2("Ms. Johnson", "English");

    School school1("Greenwood High");
    school1.addTeacher(&t1);
    school1.addTeacher(&t2);
    school1.display();

    cout << "\n===== ASSOCIATION =====\n";
    TeacherAssociation tAssoc("Mr. Brown", "Science", &school1);
    tAssoc.display();

    return 0;
}

