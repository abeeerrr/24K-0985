#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

  
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

  
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
             real * other.imag + imag * other.real);
    }

 
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
      (imag * other.real - real * other.imag) / denominator);
    }


    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real << " + " << c.imag << "i)";
        return out;
    }


    friend double magnitude(const Complex& c);
};


double sqrtApprox(double num) {
    if (num == 0) return 0;
    
    double x = num;
    double y = 1.0;
    

    for (int i = 0; i < 50; i++) {
        x = (x + y) / 2;
        y = num / x;
    }

    return x;
}

double magnitude(const Complex& c) {
    return sqrtApprox(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex c1(3, 4), c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;

    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;

    Complex prod = c1 * c2;
    cout << "c1 * c2 = " << prod << endl;

    Complex quotient = c1 / c2;
    cout << "c1 / c2 = " << quotient << endl;

    cout << "Magnitude of c1 = " << magnitude(c1) << endl;
    cout << "Magnitude of c2 = " << magnitude(c2) << endl;

    return 0;
}

