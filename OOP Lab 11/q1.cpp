#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception {
    int rows1, cols1, rows2, cols2;
    string msg;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) 
        : rows1(r1), cols1(c1), rows2(r2), cols2(c2) {
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions ("
           << rows1 << "x" << cols1 << " vs " << rows2 << "x" << cols2 << ")!";
        msg = ss.str();
    }

    const char* what() const throw() {
        return msg.c_str();
    }
};

template<typename T>
class Matrix {
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for(int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    ~Matrix() {
        for(int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void input() {
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    void print() const {
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        Matrix<int> C = A + B;
        C.print();
    } catch (DimensionMismatchException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
