#include <iostream>
using namespace std;

class Area {
private:
    float length;
    float breadth;
public:
    Area(float l, float b) 
	{
        length = l;
        breadth = b;
    }

    float returnArea() {
        return length * breadth;
    }
};
int main() {
    float len, bre;
    cout << "Enter length of the rectangle: ";
    cin >> len;
    cout << "Enter breadth of the rectangle: ";
    cin >> bre;
    Area rectangle(len, bre);
    cout << "Area of the rectangle: " << rectangle.returnArea() << endl;

    return 0;
}

