#include <iostream>
using namespace std;

class Rational {
    public:
        int numerator = 0;
        int denominator = 1;
	Rational() {
        numerator = 0;
        denominator = 1;
    	}

	Rational(int numerator_ = 0, int denominator_ = 0) : numerator(numerator_), denominator(denominator_) { };
	Rational operator+(const Rational & add); // 重载为成员函数
	Rational operator-(const Rational & subtract); // 重载为成员函数
};

Rational Rational::operator+(const Rational & add) { // 重载为成员函数
	return Rational(numerator + add.numerator, denominator + add.denominator);
}
Rational Rational::operator-(const Rational & subtract) { // 重载为成员函数
	return Rational(numerator - subtract.numerator, denominator - subtract.denominator);
}

Rational operator*(const Rational & a, const Rational & b) { // 重载为普通的函数
	return Rational(a.numerator * b.numerator, a.denominator * b.denominator);
}
Rational operator/(const Rational & a, const Rational & b) { // 重载为普通的函数
	return Rational(a.numerator / b.numerator, a.denominator / b.denominator);
}


int main() {
    Rational a(4, 4), b(1, 1);
    cout << (a + b).numerator << " " << (a + b).denominator << endl;
    cout << (a - b).numerator << " " << (a - b).denominator << endl;
	
    cout << (a * b).numerator << " " << (a * b).denominator << endl;
    cout << (a / b).numerator << " " << (a / b).denominator << endl;
    
    return 0;
}


// 运行结果如下
//  ~/Desktop ./a.out                                                                   340ms  Wed Oct 24 18:57:59 2018
// 5 5
// 3 3
// 4 4
// 4 4
