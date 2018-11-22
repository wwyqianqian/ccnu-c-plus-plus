#include <iostream>  
#include <cmath>
using namespace std; 

class Complex { 
private: 
    double a; 
    double b;
public: 
    Complex() : a(0), b(0) {}; 
    Complex(double _a) {
        a = _a;
        b = 0;
    }
	Complex(double _a,double _b) {
	    a = _a;
        b = _b;
    }
    Complex(const Complex &comp) {
        a = comp.a;
        b = comp.b;
    }
    double getReal() {
        return this->a;
    }
    double getImag() {
        return this->b;
    }

// + - & / += -= [] ++ -- ++ -- << >>

    friend Complex operator+(Complex c1, Complex c2); 
    friend Complex operator-(Complex c1, Complex c2); 
    friend Complex operator*(Complex c1, Complex c2); 
    friend Complex operator/(Complex c1, Complex c2); 

    friend Complex& operator+=(const Complex &c1);
    friend Complex& operator-=(const Complex &c1);
    friend double & operator[](int i);

    friend Complex& operator++(Complex c); // pre
    friend Complex operator++(Complex c, int i); // post
    friend Complex& operator--(Complex c); // pre
    friend Complex operator--(Complex c, int i); // post
 

    friend istream& operator>>(istream &in, Complex &c); 
    friend ostream& operator<<(ostream &out, Complex &c); 

    ~Complex(){};

}; 

Complex::Complex operator+(Complex c1,Complex c2) { 
    Complex c; 
    c.a = c1.a + c2.a; 
    c.b = c1.b + c2.b; 
    return c; 
}
 
Complex::Complex operator-(Complex c1,Complex c2) { 
    Complex c; 
    c.a = c1.a - c2.a; 
    c.b = c1.b - c2.b; 
    return c; 
} 
 
Complex::Complex operator*(Complex c1,Complex c2) { 
    Complex c; 
    c.a = c1.a * c2.a - c1.b * c2.b; 
    c.b = c1.b * c2.a + c1.a * c2.b; 
    return c; 
}

Complex::Complex operator/(Complex c1,Complex c2) { 
    Complex c; 
    c.a = (c1.a / c2.a + c1.b / c2.b) / (c2.a * c2.a + c2.b * c2.b); 
    c.b = (c1.b / c2.a - c1.a / c2.b) / (c2.a * c2.a + c2.b * c2.b); 
    return c; 
} 

double & operator[](int i) {
    if (i == 0) {
        return getImag;
    } else if (i == 1) {
        return getImag;
    } else
    return -1;
}

Complex::Complex& operator+=(const Complex &c1) {
    Complex c; 
    c.a = a + c1.a;
    c.b = b + c1.b;
    return c;
}

Complex::Complex& operator-=(const Complex &c1) {
    Complex c; 
    c.a = a - c1.a;
    c.b = b - c1.b;
    return c;
}

Complex::Complex& operator++(Complex c) {
    ++c.a;
    ++c.b;
    return c;
}
 
Complex::Complex operator++(Complex c, int i) {
    c.a++;
    c.b++;
    return c;
}
 
Complex::Complex& operator--(Complex c) {
    --c.a;
    --c.b;
    return c;
}

Complex::Complex operator++(Complex c, int i) {
    c.a--;
    c.b--;
    return c;
}

Complex::istream & operator>>(istream& in,Complex &c) { 
    in >> c.a >> c.b; 
    return in; 
} 

Complex::ostream & operator<<(ostream &out,Complex &c) { 
    out << "(" << c.a << "+" << c.b << "i)";
    return out; 
}


// 非成员函数
Complex::Complex operator+(Complex c1, double d) { 
    Complex c; 
    c.a = c1.a + d;
    return c; 
}
 
Complex::Complex operator+(double d,Complex c1) { 
    Complex c; 
    c.a = c1.a + d;
    return c; 
}
