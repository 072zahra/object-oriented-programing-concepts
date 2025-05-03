#include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    int inches;
public:
    Distance(int f, int i)   {
	feet=f;
	 inches=i;
	}
    int getFeet()
	 {
	 return feet; 
	 }
    int getInches() 
	{
	 return inches;
	  }
    void show() {
        cout << feet << " feet, " << inches << " inches";
    }
    Distance operator%(int divisor) {
        int totalInches = feet * 12 + inches;
        int remainder = totalInches % divisor;
        int quotientInches = totalInches - remainder;
        int quotientFeet = quotientInches / 12;
        quotientInches %= 12;
        return Distance(quotientFeet, quotientInches);
    }
};

int main()
 {
    Distance d1(74, 34);
    cout << "Original Distance: ";
    d1.show();
    cout << endl;
    int divisor;
    cout << "Enter divisor for % operation: ";
    cin >> divisor;
    Distance result = d1 % divisor;
    cout << " % operation: ";
    result.show();
    cout << endl;
    return 0;
}

