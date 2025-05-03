#include <iostream>
#include <string>
using namespace std;
class Student
 {
private:
    string name;
    int age;
    string address;
public:
    Student() : name("unknown"), age(0), address("not available") {} 
    void setInfo(string stname, int stage) 
	{
    name = stname;
    age = stage;
    }
    void setInfo(string stname, int stage, string staddress) 
	{
    name = stname;
    age = stage;
    address = staddress;
    }

    void printInfo()
 {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
    }
};
int main()
 {
    Student students[10];

    for (int i = 0; i < 10; ++i) {
        string name;
        cout << "Enter name for student " << i+1 << ": ";
        getline(cin, name);
        students[i].setInfo(name, 0); 
    }
    for (int i = 0; i < 10; ++i) {
        int age;
        cout << "Enter age for student " << i+1 << ": ";
        cin>>age;
       students[i].setInfo(age); 
    }
     for (int i = 0; i < 10; ++i) {
       string address;
        cout << "Enter address for student " << i+1 << ": ";
        getline(cin, address);
        students[i].setInfo(address, 0); 
    }

    cout << "Student Details:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Student " << i+1 << ":" << endl;
        students[i].printInfo();
        
        
        cout << endl;
    }
    return 0;
}
