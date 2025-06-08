//STUDENT GRADE CALCULATOR//
#include<iostream>
using namespace std;
struct student{
	string name;
	int rollnumber;
	int subjectmarks[5];
	float average;
	char grade;
};

float getaverage(int subjectmarks[],int size){
int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+subjectmarks[i];
	}
	return sum/size;
}
	char getgrade(float average){
		if(average>=90) return 'A';
		else if(average>=80) return 'B';
		else if (average >=70) return 'C';
		else if (average>=60) return 'D';
		else return 'F';
	}
	

int main(){
	int number;
	cout<<"how many student record you want to save "<<endl;
	cin>>number;
	
	student*ptr= new student[number];
	for(int i=0;i<number;i++){
		cout<<"Enter the name of "<<i+1<<" student"<<endl;
		cin.ignore();
		getline(cin,ptr[i].name);
		
		cout<<"Enter the roll number of "<<i+1<<" student"<<endl;
		cin>>ptr[i].rollnumber;
		
		cout<<"Enter the marks for 5 subject of "<<i+1<<" student"<<endl;
		for(int j=0;j<5;j++){
			cout<<"Subject "<<j+1<<" :"<<endl;
			cin>>ptr[i].subjectmarks[j];
		}
	ptr[i].average = getaverage(ptr[i].subjectmarks,5);
	ptr[i].grade= getgrade(ptr[i].average);
	}
	
	for(int i=0;i<number;i++){
		cout<<"STUDENT "<<i+1<<" RECORD"<<endl;
		cout<<"Name of "<<i+1<<" student is "<<ptr[i].name<<endl;
		cout<<"Roll number of "<<i+1<<" student is "<<ptr[i].rollnumber<<endl;
		for(int j=0;j<5;j++){
		cout<<"marks of "<<j+1<<" subject :"<<ptr[i].subjectmarks[j]<<endl;
	
	}
	cout<<"Average of 5 subject marks is "<<ptr[i].average<<endl;
	cout<<"Grade is "<<ptr[i].grade<<endl;
	}

}