#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){

    ofstream myfile("config.txt");
    if(myfile.is_open()){
        cout<<"File opened successfully"<<endl;
        myfile<<"AAAAABBBBBCCCCC"<<endl;
        myfile.close();
    }else{
        cout<<"file Failed to open"<<endl;
    }
    fstream yourfile("config.txt", ios::in | ios::out);
   if (yourfile.is_open()){
    cout<<"File reopened successfully"<<endl;
    yourfile.seekp(5,ios::beg);
    yourfile<<"XXXXX"<<endl;
    yourfile.close();
   }else
   {
    cerr<<"File Can't be reopened"<<endl;
   }

   ifstream infile("config.txt");
   string line;
   getline(infile,line);
   cout<<"After modification is: "<<line<<endl;
   infile.close();
   
    return 0;
}