#include <iostream>
using namespace std;
class LocalPhone {
private:
    string localNumber;

public:
    void inputLocalNumber() {
        cout << "Enter local phone number: ";
        cin >> localNumber;
    }
    void displayLocalNumber() {
        cout << "Local Phone Number: " << localNumber << endl;
    }
};
class NatPhone : public LocalPhone {
private:
    string cityCode;

public:
    void inputCityCode() {
        cout << "Enter city code: ";
        cin >> cityCode;
    }

    void displayCityCode() {
        cout << "City Code: " << cityCode << endl;
    }
};

class IntPhone : public NatPhone {
private:
    string countryCode;

public:
    void inputCountryCode() {
        cout << "Enter country code: ";
        cin >> countryCode;
    }

    void displayCountryCode() {
        cout << "Country Code: " << countryCode << endl;
    }
};

int main() {
    IntPhone phone;
    phone.inputLocalNumber();
    phone.inputCityCode();
    phone.inputCountryCode();
    cout << "Phone Details:" << endl;
    phone.displayLocalNumber();
    phone.displayCityCode();
    phone.displayCountryCode();
    return 0;
}


