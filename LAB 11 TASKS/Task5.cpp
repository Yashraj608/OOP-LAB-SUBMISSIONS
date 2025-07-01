#include<iostream>
#include<string>
using namespace std;

class InsufficientFundsException {
public:
    double deficit;
    InsufficientFundsException(double d) {
        this->deficit = d;
    }
    void displaymessage() {
        cout << "Insufficient funds: " << deficit << endl;
    }
};

template <class T>
class BankAccount {
    T currency;
public:
    BankAccount(T currency) {
        this->currency = currency;
    }
    
    void withdraw(T amount) {
        if(amount > currency) {
            T deficit = amount - currency;
            throw InsufficientFundsException(deficit);
        } else {
            currency -= amount;
        }
    }
    
    void showbalance() {
        cout << "Balance is: " << currency << endl;
    }
};

int main() {
    BankAccount<double> account(500.0);
    account.showbalance();

    try {
        account.withdraw(600);
    }
    catch (InsufficientFundsException& e) {
        e.displaymessage();
    }

    return 0;
}
