## Real-world Example
A simple payment system:

- Base class `Payment`
- Derived classes `CreditCardPayment` and `MobileMoneyPayment`
- Same interface `processPayment()` behaves differently at runtime.

## C++ Program

```cpp
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
```

## Expected Output

```
=== Runtime Polymorphism Demo ===

Calling processPayment() through base-class pointers:

[Credit Card] Charging 150000 UGX to Visa ending with 1234
   → Authorization successful. Receipt emailed.

[Mobile Money] Sending 75000 UGX via MTN to +256701234567
   → PIN confirmed. Transaction ID generated.

--- Using base-class reference ---
[Credit Card] Charging 150000 UGX to Visa ending with 1234
   → Authorization successful. Receipt emailed.
```

## Hand-drawn Style Illustration

```
          +-------------------+
          |     Payment       |   ← Base class
          |-------------------|
          | amount, currency  |
          | virtual           |
          | processPayment()  |   ← Virtual function
          +---------+---------+
                    |
         +----------+----------+
         |                     |
         v                     v
+------------------+   +---------------------+
| CreditCardPayment|   | MobileMoneyPayment  |
|------------------|   |---------------------|
| cardNumber       |   | phoneNumber         |
| cardType         |   | provider            |
| processPayment() |   | processPayment()    |  ← Overrides
| (overridden)     |   | (overridden)        |
+------------------+   +---------------------+

Runtime decision:

Payment* p = &creditCardObject;
p->processPayment();   →  CreditCard version is called

Payment* p = &mobileMoneyObject;
p->processPayment();   →  MobileMoney version is called
```

**Key Points:**
- The function call is resolved **at runtime** using the actual object type (dynamic binding).
- This is possible because of the `virtual` keyword and the use of a base-class pointer/reference.
- Same interface, different behaviour → classic polymorphism.

---

**How to compile and run:**

```bash
# Inheritance program
g++ -std=c++11 multilevel_inheritance.cpp -o inheritance
./inheritance

# Polymorphism program
g++ -std=c++11 polymorphism.cpp -o polymorphism
./polymorphism
```
