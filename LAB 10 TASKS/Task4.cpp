#include<iostream>
#include<string>
using namespace std;

int main(){
    string ExtraData = "SW:4.5";
    string ans;
    cout<<"Enter your choice (Autonomus car/ ElectricVehicle)"<<endl;
    getline(cin,ans);
    if(ans== "Autonomus car" ){
        size_t  colonps = ExtraData.find(':');
        string substring = ExtraData.substr(colonps+1);
       float value = stof(substring);
       cout<<"Value is: "<<value<<endl;
    }
    else if(ans=="Electric vehicle"){
size_t colonpos = ExtraData.find(':');
string substring1 =ExtraData.substr(colonpos+1);
int value =  stoi(substring1);
cout<<"Value of string is: "<<value<<endl;
    }
    return 0;
}