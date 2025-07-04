#include<iostream>
using namespace std;
class vehicle{
	protected:
		string brand;
		int speed;
		public:
			vehicle(string brand,int speed){
				this->brand=brand;
				this->speed=speed;
			}
		virtual void display(){
			cout<<"Brand Name: "<<brand<<endl;
			cout<<"Speed :"<<speed<<endl;
		}	
};

class car : public vehicle{
	protected:
		int seats;
		public:
		car(int seats,string brand,int speed):vehicle(brand ,speed){
			this->seats=seats;
		}
		
		void display() override{
			vehicle::display();
			cout<<"Seats are: "<<seats<<endl;
		}
		
};

class Electriccar : public vehicle{
	protected:
		int batterylife;
		public:
			Electriccar(int batterylife,string brand ,int speed):vehicle(brand,speed){
				this->batterylife=batterylife;
			}
			void display() override{
				vehicle::display();
				cout<<"Battery life is: "<<batterylife<<endl;
			}
};
int main(){
	string brand;
	int speed, seats,batterylife;
	cout<<"Enter the Brand Name of Electric car"<<endl;
	getline(cin,brand);
	cout<<"Enter the speed of Electric car"<<endl;
	cin>>speed;
	cout<<"Enter the seats of Electric car"<<endl;
	cin>>seats;
	cout<<"Enter the battery life of Electric car"<<endl;
	cin>>batterylife;
	
	Electriccar c1(batterylife,brand,speed);
	c1.display();
	return 0;
}
