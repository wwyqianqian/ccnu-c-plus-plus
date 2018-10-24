#include <iostream>
#include <sstream>
std::stringstream s;


class Rational {
    private:
        int numerator;
        int denominator;
    public:
        Rational();

        Rational(int numerator_, int denominator_);

        int getNumerator();

        int getDenominator();

        Rational add(Rational secondRational);

        Rational subtract(Rational secondRational);

        Rational multiply(Rational secondRational);

        Rational divide(Rational secondRational);

        int compareTo(Rational secondRational);

        bool equals(Rational secondRational);

        int intValue();

        double doubleValue();

        std::string toString();

        void simplify();
};


Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator_, int denominator_) {
    numerator = numerator_;
    denominator = denominator_;
}

int Rational::getNumerator() {
    return numerator;
}

int Rational::getDenominator() {
    return denominator;
}

Rational Rational::add(Rational secondRational) {
    Rational r;
    r.numerator = denominator * secondRational.numerator + numerator * secondRational.denominator;
    r.denominator = denominator * secondRational.denominator;
    r.simplify();
    return r;
}

Rational Rational::subtract(Rational secondRational) {
    Rational r;
    r.numerator = numerator * secondRational.denominator - denominator * secondRational.numerator;
    r.denominator = denominator * secondRational.denominator;
    r.simplify();
    return r;
}

Rational Rational::multiply(Rational secondRational) {
    Rational r;
    if (denominator == 0 || secondRational.denominator == 0) {
        std::cout << "分母不能为0" << std::endl;
    } else {
        r.numerator = numerator * secondRational.numerator;
        r.denominator = denominator * secondRational.denominator;
        r.simplify();
        return r;
    }
}

Rational Rational::divide(Rational secondRational) {
    Rational r;
    if (denominator == 0 || secondRational.denominator == 0 || secondRational.numerator == 0) {
        std::cout << "分母或者除数不能为0" << std::endl;
    } else {
        r.numerator = numerator * secondRational.denominator;
        r.denominator = denominator * secondRational.numerator;
        r.simplify();
        return r;
    }
}

int Rational::compareTo(Rational secondRational) {
    double result = subtract(secondRational).doubleValue();
    if (result == 0) {
        return 0;
    } else if (result > 0) {
        return 1;
    } else {
        return -1;
    }
}

bool Rational::equals(Rational secondRational) {
    return numerator == secondRational.numerator && denominator == secondRational.denominator ? true : false;
}

int Rational::intValue() {
    return numerator / denominator;
}

double Rational::doubleValue() {
    return (double) numerator / (double) denominator;
}

std::string Rational::toString() {
    std::stringstream ss;
    if (denominator == 1) {
        ss << numerator;
    } else {
        ss << numerator << "/" << denominator;
    }
    return ss.str();
}

void Rational::simplify() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = abs(numerator);
    int b = abs(denominator);
    while (b > 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    numerator /= a;
    denominator /= a;
}


int main() {

    Rational a = Rational(2, 3);
    Rational b = Rational(1, 2);
    std::cout << "a + b =" << a.add(b).toString() << std::endl;
    std::cout << "a - b =" << a.subtract(b).toString() << std::endl;
    std::cout << "a * b =" << a.multiply(b).toString() << std::endl;
    std::cout << "a / b =" << a.divide(b).toString() << std::endl;

    int result = a.compareTo(b);
    if (result == 0) {
        std::cout << "a = b" << std::endl;
    } else if (result == 1) {
        std::cout << "a > b" << std::endl;
    } else if (result == -1) {
        std::cout << "a < b" << std::endl;
    } else {
        return 1;
    }
    return 0;
}


// 运行结果
//  ~  ./a.out              376ms Wed Oct 24 23:26:11 2018
// a + b =7/6
// a - b =1/6
// a * b =1/3
// a / b =4/3
// a > b