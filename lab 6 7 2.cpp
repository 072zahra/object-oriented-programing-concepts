#include <iostream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y)  {
	day=d;
    month=m;
    year=y;
	}
    int getDay()
	 { 
	 return day;
	  }
    int getMonth()
	 { 
	return month;
	 }
    int getYear() 
	{ return year;
	 }
};

class Employee {
private:
    Date birthDate;
    Date joiningDate;

public:
    Employee(Date dob, Date doj) : birthDate(dob), joiningDate(doj) {}

    bool joinedWithinLastFiveYears(int currentYear) 
	{
        return (currentYear - joiningDate.getYear()) <= 5;
    }

    bool ageLessThan40(int currentYear) {
        int age = currentYear - birthDate.getYear();
        if (birthDate.getMonth() > currentYear || (birthDate.getMonth() == currentYear && birthDate.getDay() > birthDate.getDay())) {
            age--;
        }
        return age < 40;
    }
};

int main()
 {
    int currentYear;
    cout << "Enter the current year: ";
    cin >> currentYear;
    int birthDay, birthMonth, birthYear;
    cout << "Enter birth date (day:month:year): ";
    cin >> birthDay >> birthMonth >> birthYear;
    Date dob(birthDay, birthMonth, birthYear);
    int joiningDay, joiningMonth, joiningYear;
    cout << "Enter joining date (day:month:year): ";
    cin >> joiningDay >> joiningMonth >> joiningYear;
    Date doj(joiningDay, joiningMonth, joiningYear);
    Employee emp(dob, doj);
    if (emp.joinedWithinLastFiveYears(currentYear)) {
        cout << "Employee joined within the last five years"<<endl;
    } else {
        cout << "Employee did not join within the last five years."<<endl;
    }
    if (emp.ageLessThan40(currentYear)) {
        cout << " age is less than 40 yearsn"<<endl;
    } else {
        cout << " age is 40 years or above"<<endl;
    }
    return 0;
}

