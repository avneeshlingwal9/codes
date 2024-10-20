#include <iostream>
#include <string>

using namespace std;

class CreditCard {
public:
    virtual bool validate(const string& cardNumber) const = 0;
};

class MasterCard : public CreditCard {
public:
    bool validate(const string& cardNumber) const override {
        // Validate MasterCard card number based on prefixes and length
        return (cardNumber.length() == 16) &&
               (cardNumber[0] == '5') &&
               (cardNumber[1] >= '1' && cardNumber[1] <= '5');
    }
};

class Visa : public CreditCard {
public:
    bool validate(const string& cardNumber) const override {
        // Validate Visa card number based on prefixes and length
        size_t length = cardNumber.length();
        return (length == 13 || length == 16) &&
               (cardNumber[0] == '4');
    }
};

class AmericanExpress : public CreditCard {
public:
    bool validate(const string& cardNumber) const override {
        // Validate American Express card number based on prefixes and length
        return (cardNumber.length() == 15) &&
               ((cardNumber.substr(0, 2) == "34") || (cardNumber.substr(0, 2) == "37"));
    }
};

int main() {
    MasterCard masterCard;
    Visa visa;
    AmericanExpress amex;

    string masterCardNumber = "5500000000000004";
    string visaNumber = "4111111111111111";
    string amexNumber = "340000000000009";

    cout << "MasterCard is " << (masterCard.validate(masterCardNumber) ? "valid" : "invalid") << endl;
    cout << "Visa is " << (visa.validate(visaNumber) ? "valid" : "invalid") << endl;
    cout << "American Express is " << (amex.validate(amexNumber) ? "valid" : "invalid") << endl;

    return 0;
}


