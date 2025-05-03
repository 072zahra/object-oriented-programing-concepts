#include <iostream>
using namespace std;

class Rectangle 
{
private:
    double length;
    double breadth;

public:
    Rectangle() 
	{ 
	length=0.0;
	breadth=0.0; 
}
    Rectangle(double l, double b) 
 {
	length=l;
	breadth=b;
	}  
    Rectangle(double side) {
	length=side;
	breadth=side;
	}  

 double area()
  {
        return length * breadth;
    }
};

int main() {
    Rectangle rectangle1;  
    Rectangle rectangle2(78);  
    Rectangle rectangle3(96, 67);  
    cout << " rectangle with no parameters: " << rectangle1.area() << endl;
    cout << " rectangle with one parameter: " << rectangle2.area() << endl;
    cout << " rectangle with two parameters: " << rectangle3.area() << endl;

    return 0;
}
