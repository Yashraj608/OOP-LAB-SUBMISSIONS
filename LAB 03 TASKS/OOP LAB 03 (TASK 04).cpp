//24K-0737//
//Yash Raj//
#include<iostream>
using namespace std;

class laptop{
	string brand;
	string model;
	string processor;
	int Ram;
	int storage;
	bool power=false;
	
	public:
	laptop(string b,string m,string p,int r,int s){
		this->brand=b;
		this->model=m;
		this->processor=p;
		this->Ram=r;
		this->storage=s;
	}
	
	void turnOn(){
		if(!power){
			power=true;
			cout<<brand<<" Laptop is On"<<endl;
		}
	}
		
	void turnOff(){
		if(power){
			power=false;
			cout<<brand<<" laptop is Off"<<endl;
		}
	}
	
	
	void runprogram(string program){
    cout<<program<<" is running on "<<brand<<" laptop"<<endl;		
	}
	
	void checkspecs(){
		cout<<"Specifications"<<endl;
		cout<<"Laptop Brand is:"<<brand<<endl;
		cout<<"Laptop Model is:"<<model<<endl;
		cout<<"Laptop Processor is:"<<processor<<endl;
		cout<<"Laptop Ram is:"<<Ram<<endl;
		cout<<"Laptop Storage is"<<storage<<endl;
	}
	
};
int main(){
laptop bilallaptop("Lenevo","Carbon X1","intel core i5",15,256);
bilallaptop.turnOn();
bilallaptop.checkspecs();
bilallaptop.runprogram("Visual studio");
bilallaptop.turnOff();

laptop ayeshalaptop("Dell","Aspiron","intel core i7",16,256);
ayeshalaptop.turnOn();
ayeshalaptop.checkspecs();
ayeshalaptop.runprogram("Linux");
ayeshalaptop.turnOff();


}