#include <iostream>
#include <fstream>
using namespace std;

class FileHandling {
public:
    void writeFile() {
        fstream file("data.txt", ios::out);
        file << "Name: Alice\n";
        file << "Age: 22\n";
        file.close();
    }

    void appendFile() {
        fstream file("data.txt", ios::app);
        file << "Course: C++ Programming\n";
        file.close();
    }

    void readFile() {
        fstream file("data.txt", ios::in);
        string line;

        cout << "File Content:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    FileHandling obj;
    obj.writeFile();
    obj.appendFile();
    obj.readFile();
    return 0;
}

