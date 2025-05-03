#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    try {
        ifstream inputFile("ProductDescriptions.txt");
        ofstream outputFile("FilteredProducts.txt");
        if (!inputFile) {
            throw runtime_error("Unable to open input file.");
        }
        if (!outputFile) {
            throw runtime_error("Unable to open output file.");
        }
        string productName;
        while (getline(inputFile, productName)) {
            if (productName.size() > 0 && (productName[0] == 'A' || productName[0] == 'G')) {
                outputFile << productName << endl;
            }
        }
        inputFile.close();
        outputFile.close();
        cout << "Filtered products saved to FilteredProducts.txt" << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

