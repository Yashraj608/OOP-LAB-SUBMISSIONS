#include <iostream>
using namespace std;

class Patient {
    string name;
    int id;
    string testResults[5];

public:
    Patient(string name, int id, string testResults[5]) {
        this->name = name;
        this->id = id;
        for (int i = 0; i < 5; i++) {
            this->testResults[i] = testResults[i];
        }
    }

    Patient(const Patient& other) {
        name = other.name;
        id = other.id;
        for (int i = 0; i < 5; i++) {
            testResults[i] = other.testResults[i];
        }
    }

    void display() {
        cout<< "Patient Name: " <<name<< endl;
        cout<< "Patient ID: " <<id<<endl;
        cout<< "Test Results: ";
        for (int i = 0; i < 5; i++) {
            cout << testResults[i] << " ";
        }
        cout<< endl;
    }
};

int main() {
    string testResults1[5] = {"Positive","Negative","Positive","Negative","Positive"};

    Patient p1("yash raj",101,testResults1);
    Patient p2 = p1;
    p1.display();
    p2.display();

    return 0;
}
