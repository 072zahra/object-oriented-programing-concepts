#include <iostream>
#include <string>
using namespace std;
class CarComponent {
public:
    virtual void operate() = 0;
};

class Engine : public CarComponent {
public:
    void operate() override {
        cout << "Engine is running smoothly." << endl;
    }
};
class Transmission : public CarComponent {
public:
    void operate() override {
        cout << "Transmission is shifting gears seamlessly." << endl;
    }
};

class Steering : public CarComponent {
public:
    void operate() override {
        cout << "Steering wheel is turning easily." << endl;
    }
};

class Pedals : public CarComponent {
public:
    void operate() override {
        cout << "Pressing accelerator and brake pedals." << endl;
    }
};

class DashboardControls : public CarComponent {
public:
    void operate() override {
        cout << "Adjusting dashboard controls." << endl;
    }
};

class Car {
private:
    Engine carEngine;
    Transmission carTransmission;
    Steering carSteering;
    Pedals carPedals;
    DashboardControls carDashboardControls;
public:
    void start() {
        carEngine.operate();
        carTransmission.operate();
        cout << "Car started successfully." << endl;
    }
    void accelerate() {
        carPedals.operate();
        cout << "Car is accelerating smoothly." << endl;
    }
    void brake() {
        carPedals.operate();
        cout << "Car is braking safely." << endl;
    }
    void turnSteeringWheel() {
        carSteering.operate();
    }
    void adjustDashboardControls() {
        carDashboardControls.operate();
    }
};
int main() {
    Car myCar;
    myCar.start();
    myCar.accelerate();
    myCar.turnSteeringWheel();
    myCar.brake();
    myCar.adjustDashboardControls();
    return 0;
}

