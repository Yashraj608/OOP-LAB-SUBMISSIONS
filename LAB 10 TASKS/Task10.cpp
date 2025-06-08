#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream myfile("data_records.txt");
    if(myfile.is_open()){
        cout<<"file opened successfully"<<endl;
        myfile<<"Record 1"<<endl;
        myfile<<"Record 2"<<endl;
        myfile<<"Record 3"<<endl;
        myfile<<"Record 4"<<endl;
       myfile.close();
    }
    else{
        cerr<<"File failed to open"<<endl;
    }

    ifstream yourfile("data_records.txt");
    if(yourfile.is_open()){
        yourfile.seekg(0,ios::beg);
        streampos pos = yourfile.tellg();
        cout<<"position of cursor is: "<<pos<<endl;
        string line;
        getline(yourfile,line); 
        getline(yourfile,line);
        pos= yourfile.tellg();
        getline(yourfile,line);
        cout<<"Line 3: "<<line<<endl;
        yourfile.close();
    }
   
    return 0;
}