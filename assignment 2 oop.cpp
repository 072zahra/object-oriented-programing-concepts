#include <iostream>
using namespace std;
class Matrix {
private:
    int numRows;
    int numCols;
    int** data;
public:
    Matrix(int rows, int cols) : numRows(rows), numCols(cols) {
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new int[numCols];
            for (int j = 0; j < numCols; ++j)
			{
                data[i][j] = 3 ;
            }
        }
    }
    Matrix(const Matrix& other) : numRows(other.numRows), numCols(other.numCols) {
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new int[numCols];
            for (int j = 0; j < numCols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    ~Matrix()
	{
        for (int i = 0; i < numRows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    Matrix operator+(const Matrix& other) const {
        if (numRows != other.numRows || numCols != other.numCols) {
            cout << "Not valid for addition" << endl;
            exit(1);
        }
        Matrix result(numRows, numCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) const {
        if (numRows != other.numRows || numCols != other.numCols) {
            cout << "Dimension mismatch for subtraction" << endl;
            exit(1);
        }
        Matrix result(numRows, numCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        if (numCols != other.numRows) {
            cout << "Number of columns and rows should be equal for multiplication" << endl;
            exit(1);
        }
        Matrix result(numRows, other.numCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < other.numCols; ++j) {
                for (int k = 0; k < numCols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void display() const {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Matrix mat1(3, 3);
    mat1.display();
    Matrix mat2(3, 3);
    mat2.display();
    Matrix add = mat1 + mat2;
    add.display();
    Matrix sub = mat1 - mat2;
    sub.display();
    Matrix mul = mat1 * mat2;
    mul.display();
    return 0;
}
