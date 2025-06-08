#include<iostream>
using namespace std;
class Account{
protected:
	int accnum;
	int balance;
	string name,acctype;
	public:
		Account(int accnum,int balance,string name,string acctype=""){
			this->accnum=accnum;
			this->balance=balance;
			this->name=name;
			this->acctype=acctype;
		}
		void deposit(int depamount){
			cout<<"Balance Before Depostion: "<<balance<<endl;
			cout<<"Cash Deposited: "<<depamount<<endl;
			  balance += depamount;
			cout<<"Balance after the Deposition is: "<<balance<<endl;
		}
		
	virtual	void withdraw(int widamount){
			cout<<"Balance Before Withdrawl: "<<balance<<endl;
			cout<<"Amount Withdrawed: "<<widamount<<endl;
			balance-=widamount;
			cout<<"Balance After Withdrawl : "<<balance<<endl;
		}
		
		virtual void calculateInterestrate(){
			int rate;
			cout<<"Enter the interest rate :"<<endl;
			cin>>rate;
			cout<<"Interest Rate Applied on "<<acctype<<" account is: "<<rate<<endl;
		}
		
	virtual	void printStatement(int depamount, int widamount){
    cout<<"===== Statement =====" << endl;
    cout<<"Initial Balance: "<<(balance - depamount + widamount) << endl;
    cout<<"Deposited Amount: "<<depamount<<endl;
    cout<<"Balance After Deposition: "<<(balance - widamount)<<endl;
    cout<<"Withdrawn Amount: "<<widamount<<endl;
    cout<<"Balance After Withdrawal: "<<balance<<endl;
}

		
		void getAccountInfo(){
			cout<<"Account Number: "<<accnum<<endl;
			cout<<"Balance : "<<balance<<endl;
			cout<<"Holder Name: "<<name<<endl;
			cout<<"Account Type: "<<acctype<<endl;
		}
		
};

class SavingAccount : public Account{
protected:
	int interestrate;
	int minimum_balance;
	public:
		
SavingAccount(int accnum,int balance,string name,int interestrate,int minimum_balance,string acctype=""):Account(accnum,balance,name,acctype){
	this->interestrate=interestrate;
	this->minimum_balance=minimum_balance;
}	
void printStatement(int depamount,int widamount) override{
	Account::printStatement(depamount,widamount);
}

void calculateInterestrate() override{
	Account::calculateInterestrate();
}


};

class CheckingAccount : public Account{
public:
	CheckingAccount(int accnum,int balance,string name,string acctype=""):Account(accnum,balance,name,acctype){
	}
	void withdraw(int widamount) override{
		Account::withdraw(widamount);
	}
	
	void calculateInterestrate(){
		Account::calculateInterestrate();
	}
	
	void printStatement(int depamount,int widamount) override{
		Account::printStatement(depamount,widamount);
	}
};

class FixedDepositAccount : public Account{
	protected:
		string maturitydate;
		int fixedInterestRate;
	public:
		FixedDepositAccount(int accnum,int balance,string name,string maturitydate,int fixedInterestRate,string acctype=""):Account(accnum,balance,name,acctype){
			this->fixedInterestRate=fixedInterestRate;
			this->maturitydate=maturitydate;
		}
			void calculateInterestrate()override{
		Account::calculateInterestrate();
		cout<<"Fixed Interest is "<<5<<"%"<<" on Fixed Deposit Account"<<endl;
	} 
	
	void printStatement(int depamount,int widamount) override{
		Account::printStatement(depamount,widamount);
		cout<<"Maturity Date is: "<<maturitydate<<endl;
	}
};
int main(){	
	CheckingAccount C(2877466,23000,"Yash Raj","Checking Account");
	Account*a=&C;
	a->withdraw(2000);
	a->calculateInterestrate();
	a->printStatement(3000,2000);
	
	
	SavingAccount S(433323,50000,"saad",10,5000,"Saving");
	a=&S;
	a->withdraw(2000);
	a->printStatement(2000,2000);
	a->calculateInterestrate();
	
	
	FixedDepositAccount F(4663636,40000,"Mubashir","12-00-2990",5,"Fixed");
a=&F;
a->calculateInterestrate();
a->printStatement(2000,2000);
	return 0;
} 
