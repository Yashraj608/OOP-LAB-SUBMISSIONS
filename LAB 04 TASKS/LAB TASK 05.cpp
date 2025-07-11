#include<iostream>
using namespace std;
class Book{
  static int counter;
  string name;
  double price;
  int stock;
  int bookid;
  public:
  Book() : bookid(++counter),name("Unknown"),price(0.0),stock(30){}
  
  Book(const Book&b):bookid(++counter),name(b.name),price(b.price),stock(b.stock){
  	cout<<"Copy constructor is called. "<< name <<" is copied"<<endl;
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
      cout<<"Book name is "<<name<<" having id "<<bookid<<" is about "<<price<<" rupees and "<<stock<<" is left"<<endl;
  }
  
  Book(string name2,double price2,int stock2): bookid(++counter),name(name2),price(price2),stock(stock2){}
  
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
        double finalprice = price*quantity;
        if (quantity >= 5 && quantity < 10) {
            finalprice= finalprice-(finalprice * 0.05); 
        } else if (quantity >= 10) {
            finalprice = finalprice-(finalprice * 0.10);
        }
        return finalprice;
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
int Book::counter=0;
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
