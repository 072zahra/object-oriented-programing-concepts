#include <iostream>
#include <string>
using namespace std;
class Item {
protected:
    int identifier;
    string title;
    bool is_borrowed;
public:
    Item() : identifier(0), title(""), is_borrowed(false) {}
    Item(int id, const string& title) : identifier(id), title(title), is_borrowed(false) {}
    virtual ~Item() {}
    int getId() const {
        return identifier;
    }
    const string& getTitle() const {
        return title;
    }
    bool isBorrowed() const {
        return is_borrowed;
    }
    virtual int borrow() {
        if (is_borrowed) {
            return 1; 
        }
        is_borrowed = true;
        return 0;
    }
    virtual int returnItem() {
        if (!is_borrowed) {
            return 2; 
        }
        is_borrowed = false;
        return 0; 
    }
    virtual void print() const {
        cout << "ID: " << identifier << ", Title: " << title << ", Borrowed: " << (is_borrowed ? "Yes" : "No") << endl;
    }
};
class Book : public Item {
public:
    Book() : Item() {}
    Book(int id, const string& title) : Item(id, title) {}

    void print() const override {
        cout << "Book - ";
        Item::print();
    }
};
class Library {
private:
    Item** items;
    int capacity;
    int count;

    int findItem(int identifier) {
        for (int i = 0; i < count; ++i) {
            if (items[i]->getId() == identifier) {
                return i;
            }
        }
        return -1;
    }
public:
    Library(int size) : capacity(size), count(0) {
        items = new Item*[capacity];
    }

    ~Library() {
        for (int i = 0; i < count; ++i) {
            delete items[i];
        }
        delete[] items;
    }
    int addItem(Item* item) {
        if (count >= capacity) {
            return 3; 
        }
        if (findItem(item->getId()) != -1) {
            return 4; 
        }
        items[count++] = item;
        return 0; 
    }
    int removeItem(int identifier) {
        int index = findItem(identifier);
        if (index == -1) {
            return 5;
        }
        delete items[index];
        items[index] = items[--count]; 
        return 0; 
    }
    int borrowItem(int identifier) {
        int index = findItem(identifier);
        if (index == -1) {
            return 5; 
        }
        return items[index]->borrow();
    }
    int returnItem(int identifier) {
        int index = findItem(identifier);
        if (index == -1) {
            return 5; 
        }
        return items[index]->returnItem();
    }
    void listItems() const {
        for (int i = 0; i < count; ++i) {
            items[i]->print();
        }
    }
};
int main() 
{
    Library* library = new Library(10);
    int choice;
    int id;
    string title;
    do {
        cout << "Welcome TO Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. List Items" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID: ";
                cin >> id;
                cout << "Enter book title: ";
                cin >> title;
                if (library->addItem(new Book(id, title)) != 0) {
                    cout << "Error: Unable to add book. It might already exist or the library is full." << endl;
                } else {
                    cout << "Book added successfully." << endl;
                }
                break;
            case 2:
                cout << "Enter book ID to remove: ";
                cin >> id;
                if (library->removeItem(id) != 0) {
                    cout << "Error: Book not found." << endl;
                } else {
                    cout << "Book removed successfully." << endl;
                }
                break;
            case 3:
                cout << "Enter book ID to borrow: ";
                cin >> id;
                if (library->borrowItem(id) != 0) {
                    cout << "Error: Book not found or already borrowed." << endl;
                } else {
                    cout << "Book borrowed successfully." << endl;
                }
                break;
            case 4:
                cout << "Enter book ID to return: ";
                cin >> id;
                if (library->returnItem(id) != 0) {
                    cout << "Error: Book not found or was not borrowed." << endl;
                } else {
                    cout << "Book returned successfully." << endl;
                }
                break;
            case 5:
                cout << "Listing all items in the library:" << endl;
                library->listItems();
                break;
            case 6:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    delete library;
    return 0;
}

