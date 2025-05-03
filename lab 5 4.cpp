#include <iostream>
using namespace std;
const int MAX_ROWS = 30; 
const int MAX_COLUMNS = 30; 
class Matrix {
private:
    int rows;
    int columns;
    int elements[MAX_ROWS][MAX_COLUMNS];

public:
    
    Matrix(int numRows, int numColumns) : rows(numRows), columns(numColumns) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                elements[i][j] = 0;
            }
        }
    }
    int getRows() const {
        return rows;
    }
    int getColumns() const {
        return columns;
    }
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < columns) {
            elements[i][j] = value;
        } else {
            cout << "Invalid position." << endl;
        }
    }
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrices have different dimensions. Addition not possible." << endl;
            return Matrix(0, 0); 
        }
        Matrix result(rows, columns);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }

        return result;
    }
    Matrix multiply(const Matrix& other) const {
        if (columns != other.rows) {
            cout << "Number of columns of the first matrix must be equal to the number of rows of the second matrix for multiplication." << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.columns);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.columns; ++j) {
                for (int k = 0; k < columns; ++k) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }

        return result;
    }
    void display() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows1, columns1, rows2, columns2;

    cout << "Enter number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter number of columns for matrix 1: ";
    cin >> columns1;
    Matrix matrix1(rows1, columns1);
    cout << "Enter elements for matrix 1:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            int element;
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> element;
            matrix1.setElement(i, j, element);
        }
    }
    cout << "\nEnter number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter number of columns for matrix 2: ";
    cin >> columns2;

    Matrix matrix2(rows2, columns2);

    cout << "Enter elements for matrix 2:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j) {
            int element;
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> element;
            matrix2.setElement(i, j, element);
        }
    }
    cout << "\nMatrix 1:" << endl;
    matrix1.display();
    cout << "\nMatrix 2:" << endl;
    matrix2.display();
    cout << "\nSum of Matrix 1 and Matrix 2:" << endl;
    Matrix sum = matrix1.add(matrix2);
    sum.display();
    cout << "\nProduct of Matrix 1 and Matrix 2:" << endl;
    Matrix product = matrix1.multiply(matrix2);
    product.display();
    return 0;
}

