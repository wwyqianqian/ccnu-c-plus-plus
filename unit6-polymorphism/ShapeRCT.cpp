#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;

class Shape {
public:
    // 加上这个 name 变量，方便在任何时候随便拿到一个 shape 变量的时候有办法知道它是什么类型的
    // 比如判断两个矩形是否相同的时候，先判断输入是不是矩形比较好
    string name;
    Shape(string _name): name(_name) {};
    virtual double Area() = 0; // 纯虚函数
    void PriIndex(); // 注意这里 virtual 去掉了
};

// 三个形状各自写的 PriIndex 合并成 Shape 的 PriIndex()
void Shape::PriIndex() {
    cout << name << ": " << Area() << endl;
}

class Rectangle : public Shape {
public:
    int width, length; // 矩形的宽、长
    // 升级构造函数，一次性赋值
    Rectangle(int _width, int _length): Shape("Rectangle"), width(_width), length(_length) {};
    virtual double Area();
};

class Circle : public Shape {
public:
    int radius; // 圆的半径
    // 升级构造函数，一次性赋值
    Circle(int _radius): Shape("Circle"), radius(_radius) {};
    virtual double Area();
};

class Triangle : public Shape {
public:
    int a, b, c; // 三角形三边长
    // 升级构造函数，一次性赋值
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

int main() {
    Shape *pshape;
    // Rectangle *pr;
    // Circle *pc;
    // Triangle *pt;

    int n;
    cin >> n;
    // 拿到输入的形状个数以后再定义 Shape 指针数组大小，节省空间
    Shape *p[n]; // 定义基类指针数组，动态内存分配，数组存放派生类对象指针
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        switch(c) {
            case 'R':
                //pshape = new Rectangle;
                // // (Rectangle *) pshape 把 pshape 显示类型转换为 Rectangle 指针
                // // 不然编译器不知道这个 pshape 指向的 Shape 是个 Rectangle (不知道它有 width 和 length)
                // // 直接 pshape->width 的话会报错
                // cin >> ((Rectangle *)pshape)->width >> ((Rectangle *)pshape)->length; // 不能写 '.' 形式
                // 构造函数升级以后
                int width, length;
                cin >> width >> length;
                pshape = new Rectangle(width, length);
                break;
            case 'C':
                // pshape = new Circle;
                // cin >> ((Circle *)pshape)->radius;
                // 构造函数升级以后
                int radius;
                cin >> radius;
                pshape = new Circle(radius);
                break;
            case 'T':
                // pshape = new Triangle;
                // cin >> ((Triangle *)pshape)->a >> ((Triangle *)pshape)->b >> ((Triangle *)pshape)->c;
                // 构造函数升级以后
                int a, b, c;
                cin >> a >> b >> c;
                pshape = new Triangle(a, b, c);
                break;
        }
        p[i] = pshape;
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