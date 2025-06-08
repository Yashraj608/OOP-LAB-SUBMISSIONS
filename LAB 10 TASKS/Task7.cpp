#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream out("sensor_log.txt");
    if(out.is_open()){
        cout<<"Sensor File opened successfully"<<endl;
        string line;
        out<<"Sensor 3: 228-0"<<endl;
        cout<<"Position of pointer is: "<<out.tellp()<<endl;
        out<<"Sensor 4: 3643-0"<<endl;
        cout<<"Position of pointer is : "<<out.tellp()<<endl;
        out<<"Sensor 5: 0038rn"<<endl;
        cout<<"Position of pointer is : "<<out.tellp()<<endl;
        out.close();
    }
    else {
        cout<<"Sensor Failed to open"<<endl;
    }
    return 0;
}