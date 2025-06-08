#include<iostream>
using namespace std;
class Teacher;
class Student{
	string name;
	char grades[3];
	
	public:
		Student(string name,char grades[]){
			this->name=name;
			for(int i=0;i<3;i++){
				this->grades[i] = grades[i];
			}
		}
		
		void displayGrades(){
			cout<<"Grades of Student : "<<name<<endl;
			for(int i=0;i<3;i++){
				cout<<grades[i]<<" ";
			}
			cout<<endl;
		}
		friend class Teacher;
		friend float calculateAverage(Student s);
};
float calculateAverage(Student s){
 float total=0;
 for(int i=0;i<3;i++){
 	switch(s.grades[i]){
 		case 'A': 
		 total+=4.0;
		 break;
		 case 'B':
		 total+=3.0;
		 break;
		 case 'C':
		total+=2.0;
	 	break;
	 	
	 	case 'D':
	 		total=+1.0;
	 		break;
	 		default: 
	 		total+=0.0;
	 }
 }
 return total/3;
}
class Teacher{
	public:
		void updateGrade(Student& s){
			int index;
			char newgrade;
			cout<<"Enter the index(0-2) of the grade to update: "<<endl;
			cin>>index;
			cout<<"Enter the new grade: "<<endl;
			cin>>newgrade;
			
			if(index >=0 && index < 3){
				s.grades[index] = newgrade;
				cout<<"Grade updated Successfully"<<endl;
			}
			else{
				cout<<"Invalid Index"<<endl;
			}
		}
		
		void viewGrades(Student s){
			s.displayGrades();
		}
};
int main(){
	char initialgrades[3]={'A','B','C'};
	Student s("Yash",initialgrades);
	
	Teacher T;
	T.updateGrade(s);
	T.viewGrades(s);
	
	cout<<"Average is: "<<calculateAverage(s)<<endl;
	return 0;
}