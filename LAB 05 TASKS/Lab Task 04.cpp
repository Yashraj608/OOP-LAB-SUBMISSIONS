#include<iostream>
using namespace std;
class battery{
	string brand;
	int capacity;
	string type;
	public:
		battery(){
		}
		battery(string brand,int capacity,string type){
			this->brand=brand;
			this->capacity=capacity;
			this->type=type;
		}
		
		void displaydetails(){
			cout<<"Battery Name: "<<brand<<endl;
			cout<<"Battery Capacity: "<<capacity<<endl;
			cout<<"Battery type: "<<type<<endl;
		}		
};

class smartphone{
	battery b; //composition//
	string brand;
	string model;
	public:
		smartphone(string brand,string model,string bbrand,int bcapacity,string btype):b(bbrand,bcapacity,btype){
			this->brand=brand;
			this->model=model;
		}
		
		void displayphonedetails(){
			cout<<"Phone brand: "<<brand<<endl;
		    cout<<"Phone model: "<<model<<endl;
		    b.displaydetails();
		}
		
};
int main(){
	smartphone s1("Samsung","A5","Samsung battery",3000,"lithium");
	s1.displayphonedetails();
}
