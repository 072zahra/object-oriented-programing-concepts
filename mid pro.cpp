#include <iostream>
#include <string>

const int MAX_BOOKS = 100;

using namespace std;

struct Book {
    string title;
    string author;
    double price;
    int quantity;
};

class Bookstore {
private:
    Book books[MAX_BOOKS];
    int numBooks;
    bool loggedIn;

public:
    Bookstore() : numBooks(0), loggedIn(false) {}

    void login(string username, string password) {
        loggedIn = true;
    }

    void displayBooks() const {
        if (!loggedIn) {
            cout << "Please login first." << endl;
            return;
        }

        cout << "Books available in the store:" << endl;
        for (int i = 0; i < numBooks; ++i) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Price: $" << books[i].price << ", Quantity: " << books[i].quantity << endl;
        }
    }

    void addBook(const Book& book) {
        if (!loggedIn) {
            cout << "Please login first." << endl;
            return;
        }

        if (numBooks < MAX_BOOKS) {
            books[numBooks++] = book;
            cout << "Book added successfully." << endl;
        } else {
            cout << "Bookstore is full. Cannot add more books." << endl;
        }
    }

    void removeBook(string title) {
        if (!loggedIn) {
            cout << "Please login first." << endl;
            return;
        }

        int indexToRemove = -1;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].title == title) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < numBooks - 1; ++i) {
                books[i] = books[i + 1];
            }
            numBooks--;
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    void updateBook(string title, double newPrice, int newQuantity) {
        if (!loggedIn) {
            cout << "Please login first." << endl;
            return;
        }

        for (int i = 0; i < numBooks; ++i) {
            if (books[i].title == title) {
                books[i].price = newPrice;
                books[i].quantity = newQuantity;
                cout << "Book details updated successfully." << endl;
                return;
            }
        }

        cout << "Book not found." << endl;
    }
};

int main() {
    Bookstore myBookstore;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    myBookstore.login(username, password);

    int choice;
    do {
        cout << "\n1. Display Books" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Remove Book" << endl;
        cout << "4. Update Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myBookstore.displayBooks();
                break;
            case 2: {
                string title, author;
                double price;
                int quantity;
                cout << "Enter book details to add:" << endl;
                cout << "Title: ";
                cin >> title;
                cout << "Author: ";
                cin >> author;
                cout << "Price: ";
                cin >> price;
                cout << "Quantity: ";
                cin >> quantity;
                myBookstore.addBook({title, author, price, quantity});
                break;
            }
            case 3: {
                string titleToRemove;
                cout << "Enter the title of the book to remove: ";
                cin >> titleToRemove;
                myBookstore.removeBook(titleToRemove);
                break;
            }
            case 4: {
                string titleToUpdate;
                double newPrice;
                int newQuantity;
                cout << "Enter the title of the book to update: ";
                cin >> titleToUpdate;
                cout << "Enter the new price: ";
                cin >> newPrice;
                cout << "Enter the new quantity: ";
                cin >> newQuantity;
                myBookstore.updateBook(titleToUpdate, newPrice, newQuantity);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

