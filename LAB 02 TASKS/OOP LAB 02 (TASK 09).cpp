#include<iostream>
using namespace std;
struct student{
	string name;
	int rollnumber;
	int marks;
	
};

int gethighestmarks(student*ptr,int number){
	int max=ptr[0].marks;
	for(int i=0;i<number;i++){
		if(ptr[i].marks>max){
		max=ptr[i].marks;
	}
}
	return max;
}
int main(){
	int number;
	cout<<"Enter the number of records you want to save"<<endl;
	cin>>number;
	
	student*ptr= new student[number];
	
	for(int i=0;i<number;i++){
		cout<<"Enter the name of "<<i+1<<" student:"<<endl;
		cin.ignore();
		getline(cin,ptr[i].name);
		
		cout<<"Enter the roll number of student:"<<endl;
		cin>>ptr[i].rollnumber;
		
		cout<<"Enter the marks of "<<i+1<<" student:"<<endl;
		cin>>ptr[i].marks;
		}

   int maxmarks= gethighestmarks(ptr,number);
    cout<<"Highest marks are:"<<maxmarks<<"having name"<<endl;
    
    delete[]ptr;
}