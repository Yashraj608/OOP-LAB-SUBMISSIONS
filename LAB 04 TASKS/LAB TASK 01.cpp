#include<iostream>
using namespace std;
class Book{
  string name;
  double price;
  int stock;
  public:
  Book(){ //default constructor
      name="unknown";
      price=0.0;
      stock=30;
  }
  
  
  void updatebook(string newname,double newprice,int newstock){
     name=newname;
     price=newprice;
     stock=newstock;
  }
  
  void simulatepurchase(int quantity){
      int remaining=stock -quantity;
      if(quantity>stock){
          cout<<"Sorry! Not enough stock available"<<endl;
      }
      else if (remaining <5){
          cout<<"Warning ! Low Stock."<<remaining<<endl;
      }
      else {
      	stock-=quantity;
      	cout<<"Remaining Stock is "<<remaining<<endl;
	  }
  }
  
  void display(){
      cout<<"Book name is "<<name<<" and is about "<<price<<" rupees and "<<stock<<" is left"<<endl;
  }
};

int main(){
    Book b1;
    b1.display();
    b1.updatebook("atomic habbits",344.0,21);
    b1.display();
    b1.simulatepurchase(5);
    b1.simulatepurchase(10);
    b1.simulatepurchase(6);
}
