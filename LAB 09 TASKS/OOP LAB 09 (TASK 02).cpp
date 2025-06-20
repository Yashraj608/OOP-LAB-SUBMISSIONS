#include<iostream>
using namespace std;
class SmartDevice{
    public:
    virtual bool turnOn()=0;
    virtual bool turnOff()=0;
    virtual void getStatus()=0;
};
class LightBulb : public SmartDevice{
protected:
bool isOn;
int brightness;
public:
LightBulb(bool isOn,int brightness){
    this->isOn=isOn;
    this->brightness=brightness;
}

bool turnOn()override{
    isOn = true;
    brightness=100;
    return isOn;
}

bool turnOff()override{
    isOn = false;
    brightness=0;
    return false;
}

void getStatus(){
    cout<<"Light Bulb is: "<<(isOn ? "On":"Off")<<endl;
    cout<<"Current brightness level is: "<<brightness<<endl;
}
};

class Thermostat : public SmartDevice{
    protected:
    bool isOn;
    double temp;
    public:
    Thermostat(bool isOn, double temp){
        this->isOn=isOn;
        this->temp=temp;
    }
   bool turnOn() override{
    isOn=true;
    temp = 100;
    return true;
   }

   bool turnOff() override{
    isOn = false;
    temp=0;
    return !isOn;
   }

void getStatus() override{
cout<<"Thermostat is: "<<(isOn ? "On" :"Off")<<endl;
cout<<"Thermostat temperature is: "<<temp<<endl;
}
};
int main(){
    SmartDevice* Device[2];
    Device[0] = new LightBulb(false,22);
    if(Device[0]->turnOn()){
        cout<<"Light Bulb is successfully turned on"<<endl;
    }
    Device[0]->getStatus();


    Device[1] = new Thermostat(false,11);
    if(Device[0]->turnOn()){
        cout<<"Thermostat started !"<<endl;
    }
    Device[1]->getStatus();




    if(Device[0]->turnOff()){
        cout<<"Light bulb turned off successfully"<<endl;
    }
    Device[0]->getStatus();



    if (Device[1]->turnOff())
    {
        cout<<"Thermostat turned off successfully"<<endl;
    }
    Device[1]->getStatus();
    

    delete Device[0];
    delete Device[1];
    return 0;
}
