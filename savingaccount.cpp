#include <iostream>
using namespace std;

class savingaccount
 {
private:
    static double ainterestrate; 
    double savingbalance; 

public:
   savingaccount(double balance) 
   {
   savingbalance=balance ;
   }

    void monthlyinterest()
 {
 double mointerest = (savingbalance * ainterestrate) / 12.0;
   savingbalance += mointerest;
    }

    static void modifyinterest(double newvalue)
{
    ainterestrate = newvalue;
    }

    double getbalance() const
 {
        return savingbalance;
    }
};

double savingaccount::ainterestrate = 0.0;

int main() 
{
  savingaccount s1(2000.0);
  savingaccount s2(3000.0);
  savingaccount::modifyinterest(0.03);
  s1.monthlyinterest();
  s2.monthlyinterest();
  cout << "after 1 month: $" << s1.getbalance() << endl;
  cout << "after 1 month: $" << s2.getbalance() << endl;
  savingaccount::modifyinterest(0.04);
  s1.monthlyinterest();
  s2.monthlyinterest();
  cout << " after 2 months: $" << s1.getbalance() << endl;
  cout << "after 2 months: $" << s2.getbalance() << endl;
    return 0;
}

