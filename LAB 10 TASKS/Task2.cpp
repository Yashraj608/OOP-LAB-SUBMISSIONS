#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main(){
    string line ="AutonomousCar,AC101,RoboTaxi,2023,SW:4.5,CERT-AI";
    stringstream ss(line);

    string type,id,name,year,ExtraData;
    string certification;
    getline(ss,type,',');
    getline(ss,id,',');
    getline(ss,name,',');
    getline(ss,year,',');
    getline(ss,ExtraData,',');
    getline(ss,certification,',');

    cout<<"Type of vehicle: "<<type<<endl;
    cout<<"Id of vehicle: "<<id<<endl;
    cout<<"Name of vehicle is: "<<name<<endl;
    cout<<"Year : "<<year<<endl;
    cout<<"Extra Data: "<<ExtraData<<endl;
    cout<<"Certifications: "<<certification<<endl;

    return 0;
}