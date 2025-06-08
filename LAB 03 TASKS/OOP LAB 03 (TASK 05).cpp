//grocery store management system//
//Yash Raj//
//24k-0737//
#include<iostream>
using namespace std;

class grocerystore{
	private:
	int price[10];
	string items[10];
    int count;
public:
	grocerystore(){
	count=0;
	}

void additems(string item,int price){
	if(count < 10){
		items[count]=item;
		this->price[count] = price;
		cout<<item<<" added having price "<<price<<endl;
		count++;
	}
	else{
		cout<<"Full inventory"<<endl;
	}
}	

void updateprice(string item,int newprice){
for(int i=0;i<count;i++){
	if(items[i]==item){
		price[i]=newprice;
		cout<<"price of "<<item<<" is updated to "<<newprice<<endl;
	    return;
	}
}
}

void viewinventory(){
	cout<<"Inventory"<<endl;
	for(int i=0;i<count;i++){
		cout<< items[i] <<" with"<<price[i]<<endl;
	}
}

void generatereciept(string item,int quantity){
	for(int i=0;i<count;i++){
		if(items[i]==item){
			int total=price[i]*quantity;
			cout<<"Reciept"<<endl;
			cout<<item<<""<<quantity<<""<<total<<endl;
			return;
		}
	}
}
};

int main(){
	grocerystore zainabstore;
	
	zainabstore.additems("Chaat masala",15);
	zainabstore.additems("Apples",20);
	
	zainabstore.updateprice("Apples",25);
	zainabstore.viewinventory();
	zainabstore.generatereciept("Apples",4);
	
}
