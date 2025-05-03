#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string personName;
    int personAge;
    string personGender;

public:
    void setPersonInfo(string name, int age, string gender) {
        personName = name;
        personAge = age;
        personGender = gender;
    }

    void displayPersonInfo() {
        cout << "Name: " << personName << ", Age: " << personAge << ", Gender: " << personGender << endl;
    }
};
class Employee {
protected:
    string employerName;
    float dailyWages;
public:
    void setEmployeeInfo(string name, float wages) {
        employerName = name;
        dailyWages = wages;
    }

    void displayEmployeeInfo() {
        cout << "Employer Name: " << employerName << ", Daily Wages: " << dailyWages << endl;
    }
};

class Teacher : public Person, public Employee {
private:
    string teacherGrade;

public:
    void setTeacherInfo(string name, int age, string gender, string employer, float wages, string grade) {
        setPersonInfo(name, age, gender);
        setEmployeeInfo(employer, wages);
        teacherGrade = grade;
    }

    void displayTeacherInfo() {
        displayPersonInfo();
        displayEmployeeInfo();
        cout << "teacher grade is " << teacherGrade << endl;
    }
};

int main() {
    Teacher teacher1;
    teacher1.setTeacherInfo("zahra", 25, "female", "szabist", 85, "Grade a-");
    cout << "its teacher information" << endl;
    teacher1.displayTeacherInfo();
    return 0;
}

