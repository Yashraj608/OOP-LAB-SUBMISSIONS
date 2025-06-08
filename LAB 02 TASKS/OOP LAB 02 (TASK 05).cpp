//DYNAMIC STRING MANIPULATION//
#include<iostream>
using namespace std;

void concatenate(string*ptr,int number){
	string result =ptr[0];
	for(int i=1;i<number;i++){
		result =result+ptr[i];
	}
	cout<<"concatenated string is :"<<result<<endl;
}
void comparison(string*ptr,int number){
	if(ptr[0]==ptr[1]){
		cout<<"Entered strings are equal"<<endl;
	}
	else{
		cout<<"Entered strings are not eqaul"<<endl;
	}
}
void findlength(string*ptr,int number){
	for(int i=0;i<number;i++){
		cout<<"The lenghth of "<<i+1<<" string is "<<ptr[i].length()<<endl;
	}
}
int main(){
	int number;
	cout<<"Enter the number of strings"<<endl;
	cin>>number;
	
	string*ptr=new string[number];
	
	for(int i=0;i<number;i++){
		cout<<"Enter string "<<i+1<<":"<<endl;
		cin.ignore();
		getline(cin,ptr[i]);
	}
	for(int i=0;i<number;i++){
		cout<<"Entered string "<<i+1<<" is:"<<ptr[i]<<endl;	
	}
	
	concatenate(ptr,number);
	comparison(ptr,number);
	findlength(ptr,number);
	
	
}