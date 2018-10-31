#include <iostream>
using namespace std;
const double pi = 3.141593;

class Shape{
public:
    double area() {};
};

class Rectangle : public Shape {
private:
    double l, h;
public:
    Rectangle() {
        l = 1;
        h = 1;
    }
    Rectangle(double l_ = 0, double h_ = 0) {
        l = l_;
        h = h_;
    }
    double getRectangleL() {
        return l;
    }
    double getRectangleH() {
        return h;
    }
    double area() {
        return l * h;
    }

    bool operator==(const Rectangle & rec) const {
        if(this->h == rec.h && this->l == rec.l) {
            return true;
        } else {
            return false;
        }
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle() {
        radius = 1;
    }
    Circle(double r = 0) {
        radius = r;
    }
    double getRadius() {
        return radius;
    }
    double area() {
        return radius * radius * pi;
    }
};

int main() {
    Shape S;
    Rectangle R(1, 2);
    Circle C(3);

    cout << "R.area = " << R.area() << endl;
    cout << "C.area = " << C.area() << endl;

    Rectangle X(1, 2);
    Rectangle Y(1, 2);

    if (X == Y) {
        cout << "X == Y" << endl;
    }

    return 0;
}


// output:
//~/Desktop  ./a.out                            395ms  Wed Oct 31 19:37:48 2018
//R.area = 2
//C.area = 28.2743
//X == Y