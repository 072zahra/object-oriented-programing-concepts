#include <iostream>
using namespace std;
class Address {
private:
    char* street;
    char* house;
    char* city;
    char* code;

public:
	char* nullptr;
    Address() : street(nullptr), house(nullptr), city(nullptr), code(nullptr) {}

    Address(const char* street, const char* house, const char* city, const char* code) {
        setStreet(street);
        setHouse(house);
        setCity(city);
        setCode(code);
    }

    ~Address() {
        delete[] street;
        delete[] house;
        delete[] city;
        delete[] code;
    }

    const char* getStreet() const 
	{ 
	return street;
	 }
    const char* getHouse() const {
	 return house;
	  }
    const char* getCity() const {
	 return city;
	  }
    const char* getCode() const {
	 return code;
	  }

    void setStreet(const char* newStreet) {
        delete[] street;
        street = createString(newStreet);
    }

    void setHouse(const char* newHouse) {
        delete[] house;
        house = createString(newHouse);
    }

    void setCity(const char* newCity) {
        delete[] city;
        city = createString(newCity);
    }

    void setCode(const char* newCode) {
        delete[] code;
        code = createString(newCode);
    }

private:
    char* createString(const char* source) {
        if (!source)
            return nullptr;
        int length = 0;
        while (source[length] != '\0') {
            ++length;
        }
        char* dest = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            dest[i] = source[i];
        }
        return dest;
    }
};

class Person {
private:
    Address address;

public:
    Person() {}

    Person(const Address& addr) : address(addr) {}

    const Address& getAddress() const { return address; }

    void setAddress(const Address& addr) { address = addr; }
};

int main() {
    char street[100], house[100], city[100], code[100];
    cout << "Enter street name: ";
    cin.getline(street, sizeof(street));
    cout << "Enter house number: ";
    cin.getline(house, sizeof(house));
    cout << "Enter city: ";
    cin.getline(city, sizeof(city));
    cout << "Enter postal code: ";
    cin.getline(code, sizeof(code));
    Address myAddress(street, house, city, code);
    Person person(myAddress);
    cout << "Address Details:";
    cout << "Street: " << person.getAddress().getStreet() << endl;
    cout << "House: " << person.getAddress().getHouse() << endl;
    cout << "City: " << person.getAddress().getCity() << endl;
    cout << "Postal Code: " << person.getAddress().getCode() << endl;

    return 0;
}

