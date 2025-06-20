#include<iostream>
using namespace std;

class person{
	protected:
		string name;
		int age;
		public:
			person(string name,int age){
				this->name=name;
				this->age=age;
			}
			virtual void display(){
				cout<<"Name :"<<name<<endl;
				cout<<"Age :"<<age<<endl;
			}
};

class Teacher : virtual public person{
	protected: 
	string subject;
	public:
		Teacher(string subject,string name,int age):person(name,age){
			this->subject=subject;
		}
		void display() override{
			cout<<"Subject: "<<subject<<endl;
		}
};
class Researcher :virtual public person{
	protected:
		string researcharea;
		public:
			Researcher(string researcharea,string name,int age):person(name,age){
				this->researcharea=researcharea;
			}
			void display() override{
				cout<<"Research Area is: "<<researcharea<<endl;
			}
};

class professor: public Teacher,public Researcher{
	protected:
		int publications;
		public:
			professor(int publications, string researchArea, string subject, string name, int age)
        : person(name, age), Teacher(subject, name, age), Researcher(researchArea, name, age) {
        this->publications = publications;
    }
			
                void display() override{
	person::display();
	cout<<"Subject: "<<subject<<endl;
        cout<<"Research Area: "<<researcharea<<endl;
        cout<<"No: of Publications: "<<publications<<endl;
			}
};
int main(){
	string name,subject,researcharea;
	int age,publications;
	cout<<"Enter Name of professor"<<endl;
	getline(cin,name);
	cout<<"Enter Age of professor:"<<endl;
	cin>>age;
	cin.ignore();
	cout<<"Enter Research Area of professor:"<<endl;
	getline(cin,researcharea);
	cout<<"Enter Number of publications of professor:"<<endl;
	cin>>publications;
	cin.ignore();
	cout<<"Enter the Subject of professor: "<<endl;
	getline(cin,subject);
	
	professor p(publications,researcharea,subject,name,age);
	p.display();
	return 0;
}
