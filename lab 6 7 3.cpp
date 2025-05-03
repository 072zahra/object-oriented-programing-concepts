#include <iostream>
using namespace std;
class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber(double r, double i)  {
	real=r;
    imaginary=i;
	}
    double getReal() 
	{ 
	return real;
	 }
    double getImaginary() 
	{
	 return imaginary;
	  }
    void show() {
        if (imaginary < 0)
            cout << real << " - " << -imaginary << "i";
        else
            cout << real << " + " << imaginary << "i";
    }
    ComplexNumber operator+(const ComplexNumber& other) {
        double newReal = real + other.real;
        double newImaginary = imaginary + other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }
};

int main() 
{
    ComplexNumber complex1(9, 8);
    ComplexNumber complex2(3, -6);
    cout << "Complex Number 1: ";
    complex1.show();
    cout << endl;
    cout << "Complex Number 2: ";
    complex2.show();
    cout << endl;
    ComplexNumber sum = complex1 + complex2;
    cout << "Sum: ";
    sum.show();
    cout << endl;
    return 0;
}

