#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;

class Shape {
public:
    virtual double Area() = 0; // 纯虚函数
    virtual void PriIndex() = 0;
};

class Rectangle : public Shape {
public:
    int width, length; // 矩形的宽、长
    virtual double Area();
    virtual void PriIndex();
};

class Circle : public Shape {
public:
    int radius; // 圆的半径
    virtual double Area();
    virtual void PriIndex();
};

class Triangle : public Shape {
public:
    int a, b, c; // 三角形三边长
    virtual double Area();
    virtual void PriIndex();
	
};

double Rectangle::Area() { // 注意这里是 double
    return width * length;
}
void Rectangle::PriIndex() {
    cout << "Rectangle: " << Area() << endl;
}

double Circle::Area() {
    return PI * radius * radius;
}
void Circle::PriIndex() {
    cout << "Circle: " << Area() << endl;
}

double Triangle::Area() {
    double heron = (a + b + c) / 2.0;
    return sqrt(heron * (heron - a) * (heron - b) * (heron - c)); // 海伦公式：利用三角形的三边长直接求面积
}
void Triangle::PriIndex() {
    cout << "Triangle: " << Area() << endl;
}

int main() {
    Shape *p[10]; // 定义基类指针数组，动态内存分配，数组存放派生类对象指针
    Rectangle *pr;
    Circle *pc;
    Triangle *pt;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        switch(c) {
            case 'R': 
                pr = new Rectangle;
                cin >> pr->width >> pr->length; // 不能写 '.' 形式
                p[i] = pr;
                break;
            case 'C':
                pc = new Circle;
                cin >> pc->radius;
                p[i] = pc;
                break;
            case 'T':
                pt = new Triangle;
                cin >> pt->a >> pt->b >> pt->c;
                p[i] = pt;
                break;
        }
    }
    // 按照面积进行大小排序
    
    // 排序后输出结果
    for (int i = 0; i < n; ++i) {
        p[i]->PriIndex();
    }

    return 0;
}


//  ~/Desktop  ./a.out
// 3
// R 2 3
// C 4
// T 3 4 5

// Rectangle: 6
// Circle: 50.2654
// Triangle: 6