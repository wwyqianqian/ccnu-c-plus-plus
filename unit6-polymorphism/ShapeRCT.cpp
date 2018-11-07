#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const double PI = 3.14159;

class Shape {
public:
    string name;
    Shape(string _name): name(_name) {};
    virtual double Area() = 0; // 纯虚函数
    void PriIndex();
};

void Shape::PriIndex() {
    cout << name << ": " << Area() << endl;
}

class Rectangle : public Shape {
public:
    int width, length; // 矩形的宽、长
    Rectangle(int _width, int _length): Shape("Rectangle"), width(_width), length(_length) {};
    virtual double Area();
};

class Circle : public Shape {
public:
    int radius; // 圆的半径
    Circle(int _radius): Shape("Circle"), radius(_radius) {};
    virtual double Area();
};

class Triangle : public Shape {
public:
    int a, b, c; // 三角形三边长
    Triangle(int _a, int _b, int _c): Shape("Triangle"), a(_a), b(_b), c(_c) {};
    virtual double Area();
};

double Rectangle::Area() { // 注意这里是 double
    return width * length;
}

double Circle::Area() {
    return PI * radius * radius;
}

double Triangle::Area() {
    double heron = (a + b + c) / 2.0;
    return sqrt(heron * (heron - a) * (heron - b) * (heron - c)); // 海伦公式：利用三角形的三边长直接求面积
}

// 一个用于往有序装 Shape * 的 vector 里插入新 Shape 的辅助函数
// 使用的是二分查找
void AddShape(vector<Shape *> *shapes, Shape *shape) {
    int head = 0, tail = shapes->size();
    int mid = (head + tail) / 2;;
    while (head < tail) {
        if (shape->Area() < shapes->at(mid)->Area()) tail = mid;
        else head = mid + 1;
        mid = (head + tail) / 2;
    }
    vector<Shape *>::iterator it = shapes->begin();
    shapes->insert(it + tail, shape);
};

int main() {
    Shape *pshape;
    vector<Shape *> shapes;
    int n;

    // 读取输入，并添加形状至 shapes vector
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        switch(c) {
            case 'R':
                int width, length;
                cin >> width >> length;
                pshape = new Rectangle(width, length);
                break;
            case 'C':
                int radius;
                cin >> radius;
                pshape = new Circle(radius);
                break;
            case 'T':
                int a, b, c;
                cin >> a >> b >> c;
                pshape = new Triangle(a, b, c);
                break;
            default:
                pshape = new Circle(0);
                break;

        }

        // 把 pshape 按面积有序加入 shapes vector
        AddShape(&shapes, pshape);
    }

    // 排序后输出结果
    cout << "面积从小到大为:" << endl;
    for (int i = 0; i < n; ++i) {
        shapes[i]->PriIndex();
    }

    return 0;
}

// ./a.out
// 测试输入:
// 10
// C 3
// C 4
// R 3 4
// T 4 7 9
// R 3 2
// R 1 2
// C 2
// R 4 5
// T 10 5 9
// C 10

// Rectangle: 2
// Rectangle: 6
// Rectangle: 12
// Circle: 12.5664
// Triangle: 13.4164
// Rectangle: 20
// Triangle: 22.4499
// Circle: 28.2743
// Circle: 50.2654
// Circle: 314.159