#include <iostream>
#include <string>
using namespace std;

class Sales {
private:
    float Data[3];
public:
    void getData() {
        cout << "SALES DATA OF PREVIOUS THREE MONTHS :" << endl;
        for (int i = 0; i < 3; ++i)
		 {
            cout << "Month " << i + 1 << ": $";
            cin >> Data[i];
        }
    }
    void putData() const {
        cout << "SALES DATA OF PREVIOUS THREE MONTHS :" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << Data[i] << endl;
        }
    }
};
class Publication {
private:
    string Title;
    float Price;
public:
    void getData() {
        cout << "PUBLICATION TITLE IS : ";
        cin.ignore();
        getline(cin,Title);
        cout << "PUBLICATION PRICE : $";
        cin >>Price;
    }
    void putData() const {
        cout << "PUBLICATION TITLE IS: " << Title << endl;
        cout << "PUBLICATION PRICE IS: $" << Price << endl;
    }
};

class Book : public Publication, public Sales {
private:
    int page;
public:
    void getData() {
        Publication::getData();
        cout << "PAGE COUNT ARE : ";
        cin >> page;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "PAGE COUNTS : " << page << endl;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
private:
    float Time;
public:
    void getData() {
        Publication::getData();
        cout << "ENTER PLAYING TIME IN MINUTES: ";
        cin >> Time;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "PLAY TIMING :: " << Time << " MIN" << endl;
        Sales::putData();
    }
};

int main() {
    Book b;
    Tape t;
    cout << "BOOK DETAILS:" << endl;
    b.getData();
    cout << "TAPE DETAILS:" << endl;
    t.getData();
    cout << "BOOK DETAILS:" << endl;
    b.putData();
    cout << "TAPE DETAILS:" << endl;
    t.putData();
    return 0;
}

