#include <iostream>
#include <string>
using namespace std;

// Base class with virtual function
class Payment {
protected:
    double amount;
    string currency;

public:
    Payment(double amt = 0.0, string curr = "UGX") : amount(amt), currency(curr) {}

    // Virtual function – enables runtime polymorphism
    virtual void processPayment() const {
        cout << "Processing a generic payment of "
             << amount << " " << currency << endl;
    }

    // Virtual destructor (good practice)
    virtual ~Payment() {}
};

// First derived class
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string cardType;   // Visa, Mastercard, etc.

public:
    CreditCardPayment(double amt, string curr, string number, string type)
        : Payment(amt, curr), cardNumber(number), cardType(type) {}

    // Override the virtual function
    void processPayment() const override {
        cout << "[Credit Card] Charging " << amount << " " << currency
             << " to " << cardType << " ending with "
             << cardNumber.substr(cardNumber.length() - 4) << endl;
        cout << "   → Authorization successful. Receipt emailed.\n";
    }
};

// Second derived class
class MobileMoneyPayment : public Payment {
private:
    string phoneNumber;
    string provider;   // MTN, Airtel, etc.

public:
    MobileMoneyPayment(double amt, string curr, string phone, string prov)
        : Payment(amt, curr), phoneNumber(phone), provider(prov) {}

    // Override the virtual function
    void processPayment() const override {
        cout << "[Mobile Money] Sending " << amount << " " << currency
             << " via " << provider << " to " << phoneNumber << endl;
        cout << "   → PIN confirmed. Transaction ID generated.\n";
    }
};

int main() {
    cout << "=== Runtime Polymorphism Demo ===\n\n";

    // Create objects
    CreditCardPayment cc(150000.0, "UGX", "4111111111111234", "Visa");
    MobileMoneyPayment mm(75000.0, "UGX", "+256701234567", "MTN");

    // Base-class pointers pointing to derived objects
    Payment* p1 = &cc;
    Payment* p2 = &mm;

    cout << "Calling processPayment() through base-class pointers:\n\n";

    // Same function call → different behaviour (runtime polymorphism)
    p1->processPayment();   // Calls CreditCardPayment version
    cout << endl;
    p2->processPayment();   // Calls MobileMoneyPayment version

    cout << "\n--- Using base-class reference ---\n";
    Payment& ref = cc;
    ref.processPayment();   // Still calls the overridden version

    return 0;
}