#include <iostream>

using namespace std;

class Matrix2x2 {
private:
    int elements[2][2]; 

public:
   
    Matrix2x2(int a, int b, int c, int d) {
        elements[0][0] = a; elements[0][1] = b;
        elements[1][0] = c; elements[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0], elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0], elements[1][1] + other.elements[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0], elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0], elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }

    friend ostream& operator<<(ostream& out, const Matrix2x2& mat) {
        out << mat.elements[0][0] << " " << mat.elements[0][1] << endl;
        out << mat.elements[1][0] << " " << mat.elements[1][1] << endl;
        return out;
    }

    friend int determinant(const Matrix2x2& mat);

    friend class MatrixHelper;
};

int determinant(const Matrix2x2& mat) {
    return (mat.elements[0][0] * mat.elements[1][1]) - (mat.elements[0][1] * mat.elements[1][0]);
}

class MatrixHelper {
public:
    
    void updateElement(Matrix2x2& mat, int row, int col, int newValue) {
        if (row >= 0 && row < 2 && col >= 0 && col < 2) {
            mat.elements[row][col] = newValue;
            cout << "Updated element at (" << row << ", " << col << ") to " << newValue << endl;
        } else {
            cout << "Invalid index!" << endl;
        }
    }
};

int main() {
    Matrix2x2 mat1(1, 2, 3, 4);
    Matrix2x2 mat2(5, 6, 7, 8);

    cout << "Matrix 1:" << endl << mat1;
    cout << "Matrix 2:" << endl << mat2;

    Matrix2x2 sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl << sum;

    Matrix2x2 diff = mat1 - mat2;
    cout << "Difference of matrices:" << endl << diff;

    Matrix2x2 prod = mat1 * mat2;
    cout << "Product of matrices:" << endl << prod;

    cout << "Determinant of Matrix 1: " << determinant(mat1) << endl;

    MatrixHelper helper;
    helper.updateElement(mat1, 0, 1, 10);
    cout << "Updated Matrix 1:" << endl << mat1;

    return 0;
}
