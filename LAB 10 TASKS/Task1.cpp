#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream in("vehicle.txt");
    if(in.is_open()){
        cout<<"File Opened Successfully and you can read it"<<endl;
        string line;
        while(getline(in,line)){
            cout<<"Line is: "<<line<<endl;
if(line.empty() || line[0]=='#'){
    continue;
}
        }
    }
    else{
cout<<"File Failed to open"<<endl;
    }
}