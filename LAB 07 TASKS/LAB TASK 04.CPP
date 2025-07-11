#include<iostream>
using namespace std;
class Person{
	protected:
	string name,address,email;
	int id,phonenum;
	public:
		Person(string name,string address,string email,int id,int phonenum){
			this->name=name;
			this->address=address;
			this->email=email;
			this->id=id;
			this->phonenum=phonenum;
		}
	virtual	void displayInfo(){
			cout<<"Name : "<<name<<endl;
			cout<<"Address : "<<address<<endl;
			cout<<"Id : "<<id<<endl;
			cout<<"Email : "<<email<<endl;
			cout<<"Phone number : "<<phonenum<<endl;
		}
		
		friend istream& operator>>(istream& in,Person& p){
			cout<<"Enter the name: "<<endl;
			in>>p.name;
			cout<<"Enter the address: "<<endl;
			in>>p.address;
			cout<<"Enter the id :"<<endl;
			in>>p.id;
			cout<<"Enter the Email: "<<endl;
			in>>p.email;
			cout<<"Enter the phone number: "<<endl;
			in>>p.phonenum;
			return in;
		}
		string getname(){
			return name;
		}
};

 class Student : public Person{
 	protected:
 		int coursesenrolled,enrollmentyear;
 		 float gpa;
 		 public:
 		 	Student(string name,string address,string email,int id,int phonenum,int coursesenrolled,int enrollmentyear,float gpa):Person(name,address,email,id,phonenum){
 		 		this->coursesenrolled=coursesenrolled;
 		 		this->enrollmentyear=enrollmentyear;
 		 		this->gpa=gpa;
			  }
			  
			  friend istream& operator>>(istream& in, Student&s){
			  	in>>(Person&)s;
			  	cout<<"Enter the number of courses in which enrolled: "<<endl;
			  	in>>s.coursesenrolled;
			  	cout<<"Enter the year of enrollment: "<<endl;
			  	in>>s.enrollmentyear;
			  	cout<<"Enter the GPA: "<<endl;
			  	in>>s.gpa;
			  	return in;
			  }
			  
			  void displayInfo() override{
			  	cout<<"----Student Details----"<<endl;
			  	Person::displayInfo();
			  	cout<<"Courses Enrolled: "<<coursesenrolled<<endl;
			  	cout<<"Enrollment Year: "<<enrollmentyear<<endl;
			  	cout<<"GPA is : "<<gpa<<endl;
			  }
 };
 
 class Professor : public Person{
 	protected:
 		string department;
 		int coursestaught;
 		float salary;
 		public:
 			Professor(string name,string address,string email,int id,int phonenum,string department,int coursestaught,float salary):Person(name,address,email,id,phonenum){
 				this->department=department;
 				this->coursestaught=coursestaught;
 				this->salary=salary;
			 }
			 
			 void displayInfo() override{
			 	cout<<"----Professor Details----"<<endl;
			 	Person::displayInfo();
			 	cout<<"Department: "<<department<<endl;
			 	cout<<"Courses Taught: "<<coursestaught<<endl;
			 	cout<<"Salary: "<<salary<<endl;
			 }
			 
			 friend istream& operator>>(istream& in,Professor&ps){
			 	in>>(Person&)ps;
			 	cout<<"Enter the Department: "<<endl;
			 	in>>ps.department;
			 	cout<<"Enter the number of courses taught"<<endl;
			 	in>>ps.coursestaught;
			 	cout<<"Enter the Salary: "<<endl;
			 	in>>ps.salary;
			 	return in;
			 }
 };
 class Staff : public Person{
 	protected:
 		string department,position;
 		int salary;
 		public:
 		Staff(string name,string address,string email,int id,int phonenum,string department,string position,int salary):Person(name,address,email,id,phonenum){
 			this->department=department;
 			this->position=position;
 			this->salary=salary;
		 }
		 void displayInfo() override{
		 	cout<<"----Staff Details----"<<endl;
		 	Person::displayInfo();
		 	cout<<"Department: "<<department<<endl;
		 	cout<<"Position : "<<position<<endl;
		 	cout<<"Salary: "<<salary<<endl;
		 }
		 
		 friend istream& operator>>(istream& in,Staff& sf){
		 	in>>(Person&)sf;
		 	cout<<"Enter the Department: "<<endl;
		 	in>>sf.department;
		 	cout<<"Enter the Position: "<<endl;
		 	in>>sf.position;
		 	cout<<"Enter the salary: "<<endl;
		 	in>>sf.salary;
		 	return in;
		 }
 };
 
 class Course{
 	protected:
 		int courseid,credits;
 		string courseName,instructor,schedule;
 		public:
 			Course(int courseid,int credits,string courseName,string instructor,string schedule){
 				this->courseid=courseid;
 				this->credits=credits;
 				this->courseName=courseName;
 				this->instructor=instructor;
 				this->schedule=schedule;
			 }
			 
			 void registerStudent(Student &s){
			 	cout<<s.getname()<<" has been registered for this"<<courseName<<" course"<<endl;
			 }
			 
			 void calculateGrades(Student &s){
			 	cout<<"Calculating Grades for "<<s.getname()<<" in "<<courseName<<" course"<<endl;
			 	
			 }
			 
			 void displaycourse(){
			 	cout<<"Course Name: "<<courseName<<endl;
			 	cout<<"Course Id: "<<courseid<<endl;
			 	cout<<"Course Instructor: "<<instructor<<endl;
			 	cout<<"Schedule: "<<schedule<<endl;
			 	cout<<"Credit Hours: "<<credits<<endl;
			 }
 };
 
int main(){
	string choice;
Student S("Yash Raj","DHA","Yashmandhan@gmail.com",222,0333423,3,2034,3.00);
S.displayInfo();

Professor P("Yash Raj","Landhi","k240737@gmail.com",322,073462367,"Biology",3,25000);
P.displayInfo();

Staff s("Saad","Clifton","24lsaad@gmail.com",221,0337737,"Zoology","Janitor",5000);
s.displayInfo();

cout<<"Do you want to update: "<<endl;
cin>>choice;

if(choice=="Yes" || choice == "yes"){
	int num;
	cout<<"1.Update Student: "<<endl;
	cout<<"2. Update Professor: "<<endl;
	cout<<"3.Update Staff: "<<endl;
	cin>>num;
	
	switch(num){
		case 1: cin >>S; break;
		case 2: cin>>P; break;
		case 3: cin>>s; break;
		default : cout<<"Invalid Choice"<<endl;
	}
}
	return 0;
}
