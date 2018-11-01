#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a = 0, b = 0, c = 0, x1, x2, i1, i2;

    scanf("%lf %lf %lf", &a, &b, &c);
    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    i1 = -b / (2 * a);
    i2 = sqrt(4 * a * c - b * b) / (2 * a);


    if (b * b == 4 * a * c) {
        printf("x1 = x2 = %.5f", x1);
    } else if (b * b > 4 * a * c){
        printf("x1 = %.5f; x2 = %.5f", x1, x2);
    } else {
        if (i1 == 0) {
            i1 = 0.00000;
        }
        printf("x1 = %.5f + %.5fi; x2 = %.5f - %.5fi", i1, i2, i1, i2);
    }
                                                                                                             
    return 0;
}