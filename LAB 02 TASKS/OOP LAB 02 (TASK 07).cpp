//POINTERS AND FUNCTIONS//
#include<iostream>
using namespace std;
void swapintegers(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void reversearray(int*arr,int size){
	int*start=arr;
	int*end=arr+size-1;
	while(start<end){
		swap(*start,*end);
		start++;
		end--;
	}
}
void inputintegers(){
	int firstnumber,secondnumber;
	cout<<"Enter the first number"<<endl;
	cin>>firstnumber;
	cout<<"Enter the second number"<<endl;
	cin>>secondnumber;
	swapintegers(&firstnumber,&secondnumber);
	
	cout<<"Numbers after swapping are:\n"<<firstnumber<<" "<<secondnumber<<endl;
}
void inputarr(){
	int size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	int*arr= new int[size];
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	
	cout<<"Entered elements of array are:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
	
	reversearray(arr,size);
	
	cout<<"Reversed array is:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
	
	delete[]arr;
	
	
}
int main(){
	int choice;
	
		cout<<"Enter 1 to swap two integers."<<endl;
		cout<<"Enter 2 to reverse an array."<<endl;
		cout<<"Enter 0 to exit the program."<<endl;
		cin>>choice;
	switch(choice){
		case 1:
			inputintegers();
			break;
		case 2:
			inputarr();
			break;
		case 0:
			cout<<"Exiting the program"<<endl;
		default:
			cout<<"Invalid Output"<<endl;
	}
	
}