#include <iostream>
using namespace std;
class Vehicle {
public:
    virtual void display() 
{
    cout << " Its vehicle!" << endl;
    }
};

class Car : virtual public Vehicle {
public:
    void display() override
 {
    cout << "Its  car.!" << endl;
    }
};

class Bicycle : virtual public Vehicle {
public:
    void display() override 
{
    cout << "Its bicycle.!" << endl;
    }
};

class HybridVehicle : public Car, public Bicycle {
public:
    void display() override
 {
    cout << "Its hybrid vehicle.!" << endl;
    }
};
int main() {
    Car myCar;
    Bicycle myBicycle;
    HybridVehicle myHybrid;
    myCar.display();
    myBicycle.display();
    myHybrid.display();
    myHybrid.Car::display(); 
    myHybrid.Bicycle::display(); 
    return 0;
}


