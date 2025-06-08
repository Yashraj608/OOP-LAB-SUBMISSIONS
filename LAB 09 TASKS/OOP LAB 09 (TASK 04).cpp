#include<iostream>
using namespace std;
class PaymentMethod{
    public:
    virtual void processPayment(double amount)=0;
};

class CreditCard : public PaymentMethod{
protected:
string cardNumber;
public:
CreditCard(string cardNumber){
    this->cardNumber=cardNumber;
}
void processPayment(double amount) override{
if(amount <500){
    cout<<"Sorry Insufficient Balance"<<endl;
}
else{
    cout<<"Payment is being processed...."<<endl;
}
}
};

class DigitalWallet : public PaymentMethod{
protected:
double balance;
public:
DigitalWallet(double balance){
    this->balance=balance;
}

void processPayment(double amount){
    if(balance > amount){
        cout<<"Proceeding with the payment...."<<endl;
        cout<<"Remainig balance is : "<<balance-amount<<endl;
    }
    else {
        cout<<"insufficient balance ! "<<endl;
    }
}
};
int main(){
    PaymentMethod*Methods[2];
    cout<<"Method: Credit Card"<<endl;
    Methods[0] = new CreditCard("00111--yk");
    Methods[0]->processPayment(600);
cout<<" "<<endl;
    cout<<"Method: Digital Wallet"<<endl;
    Methods[1] = new DigitalWallet(1000);
    Methods[1]->processPayment(500);
    return 0;
}
