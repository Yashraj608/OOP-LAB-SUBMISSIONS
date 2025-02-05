//Yash Raj//
//24k-0737//
#include<iostream>
using namespace std;

class markerpen{
    private:
string brand;
string color;
int inklevel;
bool refillable;
public:
markerpen(string b,string c,int l,bool r){
    brand =b;
    color=c;
    inklevel=l;
    refillable=r;
}

void write(){
if(inklevel>0){
    inklevel=inklevel-10;
    cout<< color <<"marker is left with"<< inklevel <<"%"<<endl;
}
else{
    cout<< color <<"marker is empty"<<endl;
}
}


void checkstatus(){
cout<<"marker of "<<brand<<" having "<< color <<"color is left with "<< inklevel <<"%"<<endl;
}


void refill(){
if(refillable){
    inklevel =100;
    cout<< color <<"marker is refilled to 100% "<<endl;
}
else{
    cout<< color <<" marker is not refillable "<<endl;
}
}

};
int main(){
	markerpen ahmedmarker("dollar","red",20,true);
	ahmedmarker.write();
	ahmedmarker.checkstatus();
	ahmedmarker.refill();
	ahmedmarker.checkstatus();
}
