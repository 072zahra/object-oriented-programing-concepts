#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollno;

public:
    void getnum() {
        cout << "Enter roll number: ";
        cin >> rollno;
    }

    void putnum() {
        cout << "Roll number: " << rollno << endl;
    }
};

class Test : public Student {
protected:
    int marks;

public:
    void getmarks() {
        cout << "Enter marks: ";
        cin >> marks;
    }

    void putmarks() {
        cout << "Marks: " << marks << endl;
    }
};

class Sports : public Student {
protected:
    int score;

public:
    void getscore() {
        cout << "Enter score: ";
        cin >> score;
    }

    void putscore() {
        cout << "Score: " << score << endl;
    }
};

class Result : public Test, public Sports {
private:
    int total;

public:
    void display() {
      
        getmarks();
        getscore();
        total = marks + score;
      
        putmarks();
        putscore();
        cout << "Total: " << total << endl;
    }
};

int main() {
    Result result;
    result.display();
    return 0;
}

