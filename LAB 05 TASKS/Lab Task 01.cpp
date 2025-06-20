#include <iostream>
using namespace std;

class car {
private:
    int reginum;
    string model;
    string name;
    string owner;

public:
    car() {
        reginum = 0;
        model="unknown";
        name="unknown";
        owner="unknown";
    }

    void setcar(int num, string model1, string name1, string owner1) {
        reginum=num;
        model=model1;
        name=name1;
        owner=owner1;
    }

    car(const car &b, string newOwner) {
        reginum=b.reginum;
        model=b.model;
        name=b.name;
        owner=newOwner;
    }

    void display() {
        cout<<"Car Name: " <<name<<endl;
        cout<<"Model: " <<model<<endl;
        cout<<"Registration Number: " <<reginum<< endl;
        cout<<"Owner: " <<owner<<endl;
    }
};

int main() {
    car c1;
    c1.setcar(243,"Toyota", "Yaris", "Alice");
    c1.display();

    car c2(c1,"yash");
    c2.display();

    return 0;
}
