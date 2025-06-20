#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(Currency &targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 280.10) {}
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 306.19) {}
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs", 1.0) {}
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee pkr(100);

    cout << "USD to PKR: " << usd.convertTo(pkr) << " PKR" << endl;
    cout << "EUR to PKR: " << eur.convertTo(pkr) << " PKR" << endl;
    cout << "PKR to USD: " << pkr.convertTo(usd) << " USD" << endl;
    cout << "PKR to EUR: " << pkr.convertTo(eur) << " EUR" << endl;

    return 0;
}
