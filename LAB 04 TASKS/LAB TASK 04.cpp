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
  
  
  Book(const Book&b){ //copy constructor 
  	name=b.name;
  	price=b.price;
  	stock=b.stock;
  	cout<<"Copy constructor called and book "<<name<<" is copied "<<endl;
  }
  
  void updatebook(string newname, double newprice, int newstock) {
        this->name = newname;
        this->price = newprice;
        this->stock = newstock;
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
  
  Book(string name2,double price2,int stock2){ //parameterized constructor
  	name=name2;
  	price =price2;
  	stock=stock2;
  }
  
  void applydiscount(int quantity,double price){
  	if(quantity>5 && quantity<10){
  		price =price-((price/100)*5);
  		cout<<"Price for "<<quantity<<" books after applying 5% discount is "<<price<<endl;
	  }
	  else if(quantity>10){
	  	price=price-((price/100)*10);
	  	cout<<"Price for "<<quantity<<" books after applying 10% discount is "<<price<<endl;
	  	
	  }	
  }
  
   double calculatePrice(int quantity) {
        double finalPrice = price*quantity;
        if (quantity >= 5 && quantity < 10) {
            finalPrice= finalPrice-(finalPrice * 0.05); 
        } else if (quantity >= 10) {
            finalPrice = finalPrice-(finalPrice * 0.10);
        }
        return finalPrice;
    }
  
  void stockvalidationmechanism(){
  	int quantity;
  	cout<<"Enter the quantity of book"<<endl;
  	cin>>quantity;
  	if(quantity>stock){
  		cout<<"Sorry you have reached maximum quantity"<<endl;
	  }
	  else{
	  	simulatepurchase(quantity);
	  }
  }
  
  
  
   ~Book(){
 	cout<<"Destructor Called and Book named as "<<name<<"is destroyed"<<endl;
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
    Book b2("crawdads",234.0,21);
    
    
    b2.display();
    b2.applydiscount(21,234.0);
    b2.stockvalidationmechanism();
    
    Book copy=b2;
    copy.display();
    
    b2.updatebook("Patience killer",399.0,15);
    b2.display();
   
}
