//Yash raj//
//24k-0737//
#include<iostream>
using namespace std;

class TeaMug{
	private:
	string brand;
	string color;
	int capacity;
	bool currentfilllevel;
	
	public:
		TeaMug(string b,string c,int capc,bool cfl){
			brand =b;
			color=c;
			capacity=capc;
			currentfilllevel=cfl;
		}
		
	void siptea(){
		if(capacity>0){
			capacity=capacity-10;
			cout<<"Tea in mug is "<<capacity<<" left"<<endl;
		}
		else
		{
			capacity =0;
			cout<<"Mug is empty its time to refill it "<<endl;
		}
	}
	
	void checkempty(){
		cout<<"Tea Mug of "<<brand<<" having "<<color<<" color is left with "<<capacity<<"%"<<endl;
	}
	
	void refill(){
		if(currentfilllevel){
		 capacity= 100;
			cout<<"Tea Mug is refilled "<<capacity<<"%"<<endl;
		}
		else{
			cout<<"Tea Mug is not refillable"<<endl;
		}
	}
};

int main(){
	TeaMug Fatimacup("signature","white",10,true);
	Fatimacup.siptea();
	Fatimacup.checkempty();
	Fatimacup.refill();
	Fatimacup.siptea();
}