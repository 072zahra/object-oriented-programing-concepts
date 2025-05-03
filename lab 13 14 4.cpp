#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    int employeeNumber;
    string employeeName;

public:
    Employee(int number, const string& name) : employeeNumber(number), employeeName(name) {}

    virtual double salary() const = 0; 
    virtual void display() const = 0;  
};
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(int number, const string& name, double salary)
        : Employee(number, name), monthlySalary(salary) {}

    double salary() const override {
        return monthlySalary;
    }
    void display() const override {
        cout << "Employee Number: " << employeeNumber << ", Employee Name: " << employeeName << ", Monthly Salary: $" << monthlySalary << endl;
    }
};
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(int number, const string& name, double rate, double hours)
        : Employee(number, name), hourlyRate(rate), hoursWorked(hours) {}

    double salary() const override {
        return hourlyRate * hoursWorked;
    }

    void display() const override {
        cout << "Employee Number: " << employeeNumber << ", Employee Name: " << employeeName << ", Hourly Rate: $" << hourlyRate
             << ", Hours Worked: " << hoursWorked << ", Total Salary: $" << salary() << endl;
    }
};
class CommissionedEmployee : public Employee {
private:
    double baseSalary;
    double bonus;
public:
    CommissionedEmployee(int number, const string& name, double salary, double b)
        : Employee(number, name), baseSalary(salary), bonus(b) {}

    double salary() const override {
        return baseSalary + bonus;
    }
    void display() const override {
        cout << "Employee Number: " << employeeNumber << ", Employee Name: " << employeeName << ", Base Salary: $" << baseSalary
             << ", Bonus: $" << bonus << ", Total Salary: $" << salary() << endl;
    }
};
int main() {
    const int numEmployees = 3;
    Employee* employees[numEmployees];
    employees[0] = new SalariedEmployee(1, "aneee", 5000);
    employees[1] = new HourlyEmployee(2, "sadia", 15, 40);
    employees[2] = new CommissionedEmployee(3, "zahra", 3000, 500);
    cout << "Employee Details and Salary:\n";
    for (int i = 0; i < numEmployees; ++i) {
        employees[i]->display();
    }
    for (int i = 0; i < numEmployees; ++i) {
        delete employees[i];
    }
    return 0;
}

