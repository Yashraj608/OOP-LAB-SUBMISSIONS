//DYNAMIC ARRAY MANIPULATION//
#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"enter the size of an array"<<endl;
	cin>>size;
	int* arr = new int[size];
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<size;i++){
	  cin>>arr[i];
	}
	cout<<"The elements of array are:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
	
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+arr[i];
	}
	cout<<"Sum is "<<sum<<endl;
	
	
	float average;
	for(int i=0;i<size;i++){
		average =sum/size;
	}
	cout<<"The average of input array is:"<<average<<endl;
	
	int max=arr[0];
	for(int i=0;i<size;i++){
		if(arr[i]>max);
		max=arr[i];
	}
	cout<<"The maximum number is "<<max<<endl;
	
	delete[]arr;
}
