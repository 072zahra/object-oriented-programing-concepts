#include <iostream>
using namespace std;
class Area {
private:
    double length;
    double bredth;
public:
    void setDim(double l, double b) {
        length = l;
        bredth = b;
    }
    double getArea() {
        return length * bredth;
    }
};
int main() {
    double len, bre;
    cout << "Enter the length of the rectangle: ";
    cin >> len;
    cout << "Enter the breadth of the rectangle: ";
    cin >> bre;
    Area rectangle;
    rectangle.setDim(len, bre);
    double area = rectangle.getArea();
    cout << "The area of the rectangle is: " << area <<endl;
    return 0;
}
