#include<iostream>
using namespace std;
class Vehicle{
    protected:
string model;
double rate;
public:
Vehicle(string model,double rate){
    this->model=model;
    this->rate=rate;
}

virtual double getDailyRate()=0;
virtual void displayDetails()=0;

virtual ~Vehicle(){}
};

class Car: public Vehicle{
public:
Car(string model,double rate):Vehicle(model,rate){}
double getDailyRate() override{
return rate;
}

void displayDetails()override{
    cout<<"Car model is: "<<model<<endl;
    cout<<"Car Rate is: "<<rate<<endl;
}
};

class Bike: public Vehicle{
    public:
    Bike(string model,double rate):Vehicle(model,rate){}
double getDailyRate() override{
return rate;
}

void displayDetails()override{
cout<<"Bike Rate: "<<rate<<endl;
cout<<"Bike model is: "<<model<<endl;
}
};
int main(){
    Vehicle*v = new Car("Toyota",33.0);
    v->displayDetails();

    Vehicle*v1 = new Bike("Honda",55.0);
    v1->displayDetails();

    delete v,v1;
    return 0;
}
