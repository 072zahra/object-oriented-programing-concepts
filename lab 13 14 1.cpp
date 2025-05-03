#include <iostream>

using namespace std;

template <typename T>
double findAverage(T array[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    int intArray[] = {10, 20, 30, 40, 50};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "Average of intArray: " << findAverage(intArray, intSize) << endl;

    long longArray[] = {1000, 2000, 3000, 4007, 5074};
    int longSize = sizeof(longArray) / sizeof(longArray[0]);
    cout << "Average of longArray: " << findAverage(longArray, longSize) << endl;

    double doubleArray[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    cout << "Average of doubleArray: " << findAverage(doubleArray, doubleSize) << endl;

    char charArray[] = {'A', 'B', 'C', 'D', 'E'};
    int charSize = sizeof(charArray) / sizeof(charArray[0]);
    cout << "Average of charArray " << findAverage(charArray, charSize) << endl;

    return 0;
}

