#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    string seatIdentifier;

public:
    Seat(string identifier) : seatIdentifier(identifier) {}

    string getSeatIdentifier() const {
        return seatIdentifier;
    }
};

class Show {
private:
    string title;
    string date;
    string time;
    int totalBookedSeats;

public:
    Show(string title, string date, string time) : title(title), date(date), time(time), totalBookedSeats(0) {}

    string getTitle() const {
        return title;
    }

    void bookSeat() {
        totalBookedSeats++;
    }

    int getTotalBookedSeats() const {
        return totalBookedSeats;
    }
};
class Booking {
private:
    Show sho[10];
    int showCount;

public:
	Booking (){
		showCount= 0;
	}
    void add(const Show& show) {
        if (showCount < 10) {
            sho[showCount++] = show;
        } else {
            cout << "Maximum number of shows reached." << endl;
        }
    }

    void bookSeat(int showIndex) {
        if (showIndex >= 0 && showIndex < showCount) {
            sho[showIndex].bookSeat();
            cout << "Seat booked for the show " << sho[showIndex].getTitle() << "." << endl;
        } else {
            cout << "Invalid show index." << endl;
        }
    }

    void displayAvailableShows() const {
        if (showCount == 0) {
            cout << "No shows available." << endl;
        } else {
            cout << "Available Shows:" << endl;
            for (int i = 0; i < showCount; ++i) {
                cout << "Show " << i + 1 << ": " << sho[i].getTitle() << " - Booked Seats: " << sho[i].getTotalBookedSeats() << endl;
            }
        }
    }
};


int main() {
    Booking bookingSystem;
    cout << "Enter the number of shows: ";
    int numShows;
    cin >> numShows;
    for (int i = 0; i < numShows; ++i) {
        cout << "Enter details for Show " << i + 1 << ":" << endl;
        string title, date, time;
        cout << "Title: ";
        cin >> title;
        cout << "Date: ";
        cin >> date;
        cout << "Time: ";
        cin >> time;
        bookingSystem.addShow(Show(title, date, time));
    }
    cout << "Enter the show index to book a seat: ";
    int showIndex;
    cin >> showIndex;
    bookingSystem.bookSeat(showIndex);
    bookingSystem.displayAvailableShows();
    return 0;
}

