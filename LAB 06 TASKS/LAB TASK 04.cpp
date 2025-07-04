#include<iostream>
using namespace std;

class Account{
protected:
int accountnumber;
float balance;
public:
      Account(int accountnumber,float balance){
	this->accountnumber=accountnumber;
	this->balance=balance;
}	

    virtual void display(){
	cout<<"Account number is: "<<accountnumber<<endl;
	cout<<"Balance is: "<<balance<<endl;
}
};

class SavingsAccount: public Account{
protected:
	float interestrate;
	public:
	SavingsAccount(float interestrate,int accountnumber,float balance):Account(accountnumber,balance){
		this->interestrate=interestrate;
	}
	
	 void display() override{
		Account::display();
		cout<<"Interest Rate is: "<<interestrate<<endl;
	}
	
};

class CheckingAccount: public Account{
	protected:
		float overdraftlimit;
		public:
			CheckingAccount(int accountnumber,float balance,float overdraftlimit):Account(accountnumber,balance){
				this->overdraftlimit=overdraftlimit;
			}
			
			void display() override{
				Account::display();
				cout<<"Over draft limit is:"<<overdraftlimit<<endl;
			}
};
int main(){
	int accountnumber;
	float balance,interestrate,overdraftlimit;
	
	cout<<"Enter the Account Number:"<<endl;
	cin>>accountnumber;
	cout<<"Enter the balance:"<<endl;
	cin>>balance;
	cout<<"Enter the interest rate:"<<endl;
	cin>>interestrate;
	cout<<"Enter the over draft limit: "<<endl;
	cin>>overdraftlimit;
	
	SavingsAccount A1(interestrate,accountnumber,balance);
	A1.display();
	
	CheckingAccount C1(accountnumber,balance,overdraftlimit);
	C1.display();
	
	return 0;
}
