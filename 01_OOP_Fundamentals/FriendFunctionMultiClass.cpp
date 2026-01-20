#include <iostream>
using namespace std;

class Professor;
class Teacher;

class Student {
private:
    string name;
    int rollNo;

public:
    Student(string n, int r) {
        name = n;
        rollNo = r;
    }

    friend void showDetails(Student, Professor, Teacher);
};

class Professor {
private:
    string name;
    string subject;

public:
    Professor(string n, string s) {
        name = n;
        subject = s;
    }

    friend void showDetails(Student, Professor, Teacher);
};

class Teacher {
private:
    string name;
    int experience;

public:
    Teacher(string n, int e) {
        name = n;
        experience = e;
    }

    friend void showDetails(Student, Professor, Teacher);
};

// Friend Function
void showDetails(Student s, Professor p, Teacher t) {
    cout << "---- College Details ----\n";
    cout << "Student Name: " << s.name << ", Roll No: " << s.rollNo << endl;
    cout << "Professor Name: " << p.name << ", Subject: " << p.subject << endl;
    cout << "Teacher Name: " << t.name << ", Experience: " << t.experience << " years\n";
}

int main() {
    Student s("Rahul", 101);
    Professor p("Dr. Sharma", "Computer Science");
    Teacher t("Anita", 12);

    showDetails(s, p, t);
    return 0;
}

