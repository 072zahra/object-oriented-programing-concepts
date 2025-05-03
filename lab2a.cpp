#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int accountNumber;
    float balance;
};

void  LowBalance(Customer customers[], int size)
 {
    cout << "Customers with balance less :" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (customers[i].balance < 200) {
            cout << customers[i].name << endl;
            found = true;
        }
    }
}

void increaseBalance(Customer customers[], int size) {
    cout << "Updated balances for customers :" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (customers[i].balance > 1000) {
            customers[i].balance += 100;
            cout << customers[i].name << ": $" << customers[i].balance << endl;
            found = true;
        }
    }
    
}

int main() {
    const int numCustomers = 10; 
    Customer customers[numCustomers];
    cout << "Enter customer information:" << endl;
    for (int i = 0; i < numCustomers; ++i) {
        cout << "Customer " << i+1 << " name: ";
        getline(cin, customers[i].name);
        cout << "Customer " << i+1 << " account number: ";
        cin >> customers[i].accountNumber;
        cout << "Customer " << i+1 << " balance: $";
        cin >> customers[i].balance;
        cin.ignore();
    }
   LowBalance(customers, numCustomers);
    cout << endl;
    increaseBalance(customers, numCustomers);

    return 0;
}

