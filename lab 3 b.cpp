#include <iostream>
using namespace std;
class Employee {
private:
    float salary;
    int workinghour;
public:
    void getInfo(float sal, int hours) 
	{
        salary = sal;
        workinghour = hours;
    }
    void addSal()
	 {
        if (salary < 500)
         salary += 10;
    }
    void addWork()
	{
        if (workinghour > 6)
            salary += 5;
    }
    void printSalary() {
        cout << "Final salary: $" << salary << endl;
    }
};

int main() {
	Employee e;
    float salary;
    int workinghour;
    cout << "Enter salary of the employee: $";
    cin >> salary;
    cout << "Enter number of hours of work per day: ";
    cin >>workinghour;
    e.getInfo(salary, workinghour);
    e.addSal();
    e.addWork();
    e.printSalary();
    return 0;
}

