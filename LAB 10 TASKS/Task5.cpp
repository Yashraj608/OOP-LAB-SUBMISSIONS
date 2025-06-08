#include<iostream>
#include<string>
using namespace std;

int main(){
    string ExtraData = "SW:4.5";
    string ans;
    cout << "Enter your choice (Autonomus car/ ElectricVehicle)" << endl;
    getline(cin, ans);

    if(ans == "Autonomus car"){
        size_t colonps = ExtraData.find(':');
        string substring = ExtraData.substr(colonps + 1);
        float value = stof(substring);
        cout << "Value is: " << value << endl;
    }
    else if(ans == "Electric vehicle"){
        size_t colonpos = ExtraData.find(':');
        string substring1 = ExtraData.substr(colonpos + 1);
        int value = stoi(substring1);
        cout << "Value of string is: " << value << endl;
    }
    else if(ans == "HybridTruck"){
        string ExtraData = "Cargo:X|Battery:Y";
        size_t colonpos = ExtraData.find(':');
        size_t pipepos = ExtraData.find('|');
        string substring = ExtraData.substr(colonpos + 1, pipepos - colonpos - 1);
        cout << "Cargo: " << substring << endl;
        size_t colonpos2 = ExtraData.find(':', pipepos);
        string substring1 = ExtraData.substr(colonpos2 + 1);
        cout << "Battery: " << substring1 << endl;
    }else{
        cerr<<"Invalid Vehicle Type"<<endl;
    }
    return 0;
}
