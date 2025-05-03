class Student {
#include <iostream>
private:
    int rollNumber;

public:
    void inputRollNumber() {
        std::cout << "Enter roll number: ";
        std::cin >> rollNumber;
    }

    void displayRollNumber() {
        std::cout << "Roll number: " << rollNumber << std::endl;
    }
};

class Test : public Student {
private:
    int testMarks;
public:
    void inputTestMarks() {
        std::cout << "Enter marks obtained in the test: ";
        std::cin >> testMarks;
    }

    void displayTestMarks() {
        std::cout << "Marks obtained in the test: " << testMarks << std::endl;
    }
};

class Sports : public Student {
private:
    int sportsScore;

public:
    void inputSportsScore() {
        std::cout << "Enter sports score: ";
        std::cin >> sportsScore;
    }

    void displaySportsScore() {
        std::cout << "Sports score: " << sportsScore << std::endl;
    }
};

class Result : public Test, public Sports {
private:
    int totalScore;
public:
    void displayResult() {
        inputRollNumber();
        inputTestMarks();
        inputSportsScore();
        totalScore = Test::testMarks + Sports::sportsScore;
        displayRollNumber();
        displayTestMarks();
        displaySportsScore();
        std::cout << "Total score: " << totalScore << std::endl;
    }
};

int main() {
    Result result;
    result.displayResult();
    return 0;
}

