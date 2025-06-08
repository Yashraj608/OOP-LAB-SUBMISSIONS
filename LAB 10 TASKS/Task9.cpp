#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ofstream myfile("large_log.txt");
    if(myfile.is_open()){
        cout<<"File opened Successfully"<<endl;
    myfile<<"This is the first log"<<endl;
    myfile<<"This is the Second log"<<endl;
    myfile<<"And this is the third"<<endl;
    }else{
        cerr<<"File failed to open"<<endl;
    }

    ifstream yourfile("large_log.txt");
    if(yourfile){
        cout<<"File is ready to read"<<endl;
        char line[11];
        yourfile.read(line,10);
        cout<<"First 10 characters are: "<<line<<endl;
    streampos pos= yourfile.tellg();
    cout<<"Current position after reading the first 10 characters : "<<pos<<endl;
    yourfile.read(line,10);
    cout<<"Second 10 characters are: "<<line<<endl;
    pos = yourfile.tellg();
    cout<<"After reading the 10 characters for second time the position is: "<<pos<<endl;
    }else{
           cerr<<"File failed to open"<<endl;
    }
    return 0;
}