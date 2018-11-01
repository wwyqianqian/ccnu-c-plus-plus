#include <iostream>
using namespace std;
const double pi = 3.14159;
double circleArray[1000];

class Circle {
    private:
    	double radius;
    public:
    	Circle(double r = 0) { // 构造函数，写入半径
    		radius = r;
    	}

        double getradius() { // 访问半径
            return radius;
        }
        
    	double area() {
    		return radius * radius * pi;
    	}
};

double sum(Circle circleArray[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += circleArray[i].area();
    }
    return sum;
}

int main() {
	double r;
	cout << "How many circles: ";
	int size;
	cin >> size;

	int i;
    Circle circleArray[size]; // 声明类的数组

	for (i = 0; i < size; i++) {
		cin >> r;
		circleArray[i] = Circle(r); // 调用函数
	}

    cout <<  sum(circleArray, size) << endl;

    return 0;
}