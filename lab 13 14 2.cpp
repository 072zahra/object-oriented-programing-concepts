#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("employeeData.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    double hoursWorked, hourlyRate, stateTaxRate, federalTaxRate;
    double grossSalary, netSalary;
    while (inputFile >> hoursWorked >> hourlyRate >> stateTaxRate >> federalTaxRate) {
        grossSalary = hoursWorked * hourlyRate;
        netSalary = grossSalary * (1 - stateTaxRate - federalTaxRate);
        cout << "Hours Worked: " << hoursWorked 
             << ", Hourly Rate: $" << hourlyRate 
             << ", State Tax Rate: " << stateTaxRate * 100 << "%" 
             << ", Federal Tax Rate: " << federalTaxRate * 100 << "%" << endl;
        cout << "Gross Salary: $" << grossSalary 
             << ", Net Salary: $" << netSalary << endl;
        cout << "-----------------------------------------" << endl;
    }
    inputFile.close();
    return 0;
}


