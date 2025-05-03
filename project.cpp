#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Book
 {
    string title;
    string author;
    double price;
    int quantity;

    Book(string t, string a, double p, int q) 
    {
	title=t;
	author=a;
	price=p;
    quantity=q;
    }
};
class Bookstore {
private:
    vector<Book> books;
    bool loggedIn;

public:
    Bookstore() : loggedIn(false) {}
    void login(string username, string password) 
	{
        loggedIn = true;
    }
    void displayBooks() const {
        if (!loggedIn)
		 {
            cout << "LOGIN FIRST." << endl;
            return;
        }

        cout << "AVAILABLE BOOKS IN STORE:" << endl;
 for (const auto& book : books)
   {
    cout << "Title: " << book.title << ", Author: " << book.author << ", Price: $" << book.price << ", Quantity: " << book.quantity << endl;
   }
    }
    void addBook(const Book& book)
	 {
        if (!loggedIn) {
            cout << "LOGIN" << endl;
            return;
        }

        books.push_back(book);
        cout << "ADDED BOOK" << endl;
    }

    void removeBook(string title) {
        if (!loggedIn) {
            cout << "PLEASE LOGIN" << endl;
            return;
        }
auto it = find_if(books.begin(), books.end(), [title](const Book& b){ return b.title == title; 
 });
        if (it != books.end()) {
            books.erase(it);
            cout << "SUCCESFULLY REMOVED" << endl;
        } else {
            cout << "NOT FOUND **." << endl;
        }
    }
    void updateBook(string title, double newPrice, int newQuantity) 
	{
        if (!loggedIn)
		 {
            cout << "LOGIN FIRST:**  " << endl;
            return;
        }
auto it = find_if(books.begin(), books.end(), [title](const Book& b) 
{ 
 return b.title == title;
 }
);
        if (it != books.end()) {
            it->price = newPrice;
            it->quantity = newQuantity;
            cout << "SUCCESSFULLY UPDATED:::" << endl;
        } else {
            cout << "NO BOOK FOUND%%" << endl;
        }
    }
};

int main() 
{
    Bookstore myBookstore;
    string username, password;
    cout << "ENTER USERNSME ::: ";
    cin >> username;
    cout << "ENTER PASSWORD ##  ";
    cin >> password;
    myBookstore.login(username, password);
    cout << "ADDIND BOOKS ##" << endl;
    myBookstore.addBook(Book("ATOMIC HABBITS", "MARK", 56.77, 60));
    myBookstore.addBook(Book("ALLAH LOVES", "OMAR SULEMAN", 10.99, 80));
    cout << "DISPLAYING BOOKS IN STORE:::" << endl;
    myBookstore.displayBooks();
    string titleToUpdate;
    double newPrice;
    int newQuantity;
    cout << "ENTER THE TITLE OF BOOK TO UPDATE: ";
    cin.ignore();
    getline(cin, titleToUpdate);
    cout << "NEW PRICE IS: ";
    cin >> newPrice;
    cout << "NEW QUANTITY IS: ";
    cin >> newQuantity;
    myBookstore.updateBook(titleToUpdate, newPrice, newQuantity);
    string titleToRemove;
    cout << "BOOK THAT YOU WANT TO REMOVED::: ";
    cin.ignore();
    getline(cin, titleToRemove);
    myBookstore.removeBook(titleToRemove);
    cout << "DISPLAYING AFTER APPLYING OPERATIONS:::" << endl;
    myBookstore.displayBooks();

    return 0;
}

