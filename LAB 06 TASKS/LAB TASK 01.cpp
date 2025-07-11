#include<iostream>
using namespace std;

class Employee{
	protected:
	string name;
	float salary;
	public:
		Employee(string name,float salary){
			this->name=name;
			this->salary=salary;
		}
		
		virtual void displaydetails(){
			cout<<"Name of employee is: "<<name<<endl;
			cout<<"Salary of employee is: "<<salary<<endl;
		}
};
class Manager: public Employee{
	float bonus;
	public:
		Manager(string name,float salary,float bonus):Employee(name,salary){
			this->bonus=bonus;
		}
		
		void displaydetails() override {
			cout<<"Name of employee is: "<<name<<endl;
			cout<<"Salary of employee is: "<<salary<<endl;
			cout<<"Bonus of employee is: "<<bonus<<endl;
		}
};
int main(){
	
	Manager m("Yash Raj",5000,1000);
	m.displaydetails();
	return 0;
}
