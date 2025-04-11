#include <iostream>

using namespace std;

class Vector2D {
private:
    double x, y;

public:
    
    Vector2D(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);
};

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}


int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

   
    Vector2D sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;


    Vector2D diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;


    Vector2D scaled = v1 * 2.5;
    cout << "v1 * 2.5 = " << scaled << endl;

  
    double dotProd = dotProduct(v1, v2);
    cout << "Dot product of v1 and v2 = " << dotProd << endl;

    return 0;
}
