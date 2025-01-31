//EMPLOYEE MANAGEMENT SYSTEM//
#include<iostream>
#include<string>
using namespace std;

struct Employee{
	int employeeid;
	string name;
	string department;
	int salary;
};
int main(){
	int number;
	cout<<"Enter the number of employees"<<endl;
	cin>>number;
	Employee* ptr= new Employee[number];
	for(int i=0;i<number;i++){
		cout<<"Enter the employee id of "<<i+1<<" employee"<<endl;
		cin>> ptr[i].employeeid;
		
		cin.ignore();
		cout<<"Enter the name of "<<i+1 <<" employees"<<endl;
		getline(cin,ptr[i].name);
		
		cout<<"Enter the department of "<<i+1<<" employee"<<endl;
		cin>>ptr[i].department;
		
		cout<<"Enter the salary of "<<i+1<<" employee"<<endl;
		cin>>ptr[i].salary;
	}
	
	for(int i=0;i<number;i++){
		cout<<"Employee id of "<<i+1<<" is "<<ptr[i].employeeid<<endl;
		cout<<"Name of "<<i+1<<" employee is "<<ptr[i].name<<endl;
		cout<<"Department name of "<<i+1<<" employee is "<<ptr[i].department<<endl;
		cout<<"Salary of "<<i+1<<" employee"<<endl;
	}
	int searchid,employeesno;
	cout<<"Enter the number of employees you want to search"<<endl;
	cin>>employeesno;
	for(int i=0;i<employeesno;i++){
		cout<<"Enter the employee search id"<<endl;
		cin>>searchid;
		bool found =false;
		for(int j=0;j<employeesno;j++){  
			if(ptr[j].employeeid==searchid){
			cout<<" Id Matched"<<endl;
			cout<<"Name is "<<ptr[j].name<<endl;
			cout<<"ID is "<<ptr[j].employeeid<<endl;
			cout<<"Department is "<<ptr[j].department<<endl;
			cout<<"salary is "<<ptr[j].salary<<endl;
			found=true;
			break;
		}
		}
		if(!found){
			cout<<"ID NOT MATCHED"<<endl;
		}
	}

delete[]ptr;
	
	}
