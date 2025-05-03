#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string sender, recipient, senderAddress, recipientAddress;
    double weight, costPerOunce;

public:
    Package(const string& s, const string& r, const string& sa, const string& ra, double w, double c)
        : sender(s), recipient(r), senderAddress(sa), recipientAddress(ra), weight(w > 0 ? w : 1), costPerOunce(c > 0 ? c : 0.01) {}

    double calculateCost() const { return weight * costPerOunce; }

    void displayInfo() const {
        cout << "Sender: " << sender << "\nRecipient: " << recipient << "\nSender Address: " << senderAddress
             << "\nRecipient Address: " << recipientAddress << "\nWeight: " << weight << " ounces"
             << "\nCost per ounce: $" << costPerOunce << "\n";
    }

    ~Package() {}
};

class TwoDayPackage : public Package {
protected:
    double flatFee;

public:
    TwoDayPackage(const string& s, const string& r, const string& sa, const string& ra, double w, double c, double f)
        : Package(s, r, sa, ra, w, c), flatFee(f) {}

    double calculateCost() const { return Package::calculateCost() + flatFee; }

    void displayInfo() const {
        Package::displayInfo();
        cout << "Flat fee for two-day delivery: $" << flatFee << "\nTotal cost: $" << calculateCost() << "\n";
    }
};

class OvernightPackage : public Package {
protected:
    double additionalFeePerOunce;

public:
    OvernightPackage(const string& s, const string& r, const string& sa, const string& ra, double w, double c, double a)
        : Package(s, r, sa, ra, w, c), additionalFeePerOunce(a) {}

    double calculateCost() const { return weight * (costPerOunce + additionalFeePerOunce); }

    void displayInfo() const {
        Package::displayInfo();
        cout << "Additional fee per ounce for overnight delivery: $" << additionalFeePerOunce << "\nTotal cost: $" << calculateCost() << "\n";
    }
};
int main() {
    string sender, recipient, senderAddr, recipientAddr;
    double weight, cost, flatFee, additionalFee;
    cout << "Enter sender's name: ";
    cin >> sender;
    cout << "Enter recipient's name: ";
    cin >> recipient;
    cout << "Enter sender's address: ";
    cin >> senderAddr;
    cout << "Enter recipient's address: ";
    cin >> recipientAddr;
    cout << "Enter package weight (ounces): ";
    cin >> weight;
    cout << "Enter cost per ounce: ";
    cin >> cost;
    cout << "Enter flat fee for two-day delivery: ";
    cin >> flatFee;
    cout << "Enter additional fee per ounce for overnight delivery: ";
    cin >> additionalFee;
    Package regularPackage(sender, recipient, senderAddr, recipientAddr, weight, cost);
    TwoDayPackage twoDayPackage(sender, recipient, senderAddr, recipientAddr, weight, cost, flatFee);
    OvernightPackage overnightPackage(sender, recipient, senderAddr, recipientAddr, weight, cost, additionalFee);
    cout << "\nDetails of Regular Package:\n";
    regularPackage.displayInfo();
    cout << "\nDetails of Two Day Package:\n";
    twoDayPackage.displayInfo();
    cout << "\nDetails of Overnight Package:\n";
    overnightPackage.displayInfo();
    return 0;
}

