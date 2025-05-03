#include <iostream>
#include <string>
using namespace std;
struct Employee {
    string name;
    float salary;
    int hoursWorked;
};

void adjustSalary(Employee &emp) {
    if (emp.hoursWorked >= 12) 
	{
        emp.salary += 150;
    }
	 else if (emp.hoursWorked >= 10) {
        emp.salary += 100;
    } 
	else if (emp.hoursWorked >= 8) {
        emp.salary += 50;
    }
}

int main() {
    const int numEmployees = 10;
    Employee employees[numEmployees];
    cout << "Enter employee information:" << endl;
    for (int i = 0; i < numEmployees; ++i)
	{
        cout << "Employee " << i+1 << " name: ";
        getline(cin, employees[i].name);
        cout << "Employee " << i+1 << " salary: $";
        cin >> employees[i].salary;
        cout << "Employee " << i+1 << " hours of work: ";
        cin >> employees[i].hoursWorked;
        cin.ignore(); 
    }
    for (int i = 0; i < numEmployees; ++i)
	 {
        adjustSalary(employees[i]);
    }
    cout << "Employee salaries after adjustment:" << endl;
    for (int i = 0; i < numEmployees; ++i) 
	{
        cout << employees[i].name << ": $" << employees[i].salary << endl;
    }
    return 0;
}

