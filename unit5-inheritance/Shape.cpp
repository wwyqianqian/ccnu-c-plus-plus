#include <cmath>
#include <iostream>
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
void Rectangle::PriIndex() { cout << "Rectangle: " << Area() << endl; }

double Circle::Area() { return PI * radius * radius; }
void Circle::PriIndex() { cout << "Circle: " << Area() << endl; }

double Triangle::Area() {
  double heron = (a + b + c) / 2.0;
  return sqrt(heron * (heron - a) * (heron - b) *
              (heron - c)); // 海伦公式：利用三角形的三边长直接求面积
}
void Triangle::PriIndex() { cout << "Triangle: " << Area() << endl; }

// Xor swapping
// Can even be used on pointer addresses
// Original variables are wrapped by parentheses. e.g. (x), (y)
// x = (x) ^ (y)
// y = x ^ (y) => (x) ^ (y) ^ (y) => (x)
// x = x ^ y => (x) ^ (y) ^ (x) => y
void swap(Shape **shape1, Shape **shape2) {
  shape1 = (Shape **)((unsigned long)shape1 ^ (unsigned long)shape2);
  shape2 = (Shape **)((unsigned long)shape1 ^ (unsigned long)shape2);
  shape2 = (Shape **)((unsigned long)shape1 ^ (unsigned long)shape2);
}

int partition(Shape **shape, int left, int right) {
  // select the right-most element as the pivot
  Shape *pivotShape = *(shape + right);
  double pivotArea = pivotShape->Area();
  // store current swappable index, also helpful while restoring the pivot
  int lastIdx = left;
  // iterate from left to right except the right-most protected pivot
  for (int i = left; i < right; i++) {
    double area = (*(shape + i))->Area();
    if (area < pivotArea) {
      // found an element less than the pivot
      // swap it with the element at current swappable index
      swap(*(shape + lastIdx), *(shape + i));
      // move to next swappable index
      lastIdx++;
    }
  }
  // restore the protected pivot by swapping it with the element at current
  // swappable index
  swap(*(shape + lastIdx), *(shape + right));
  // pivot index used in this partition
  return lastIdx;
}

// An implementation of quick sort
void quicksort(Shape **shape, int left, int right) {
  if (left >= right)
    return;
  int pivot = partition(shape, left, right);
  quicksort(shape, left, pivot);
  quicksort(shape, pivot + 1, right);
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
    switch (c) {
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

  quicksort(p, 0, n - 1);

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

// Triangle: 6
// Rectangle: 6
// Circle: 50.2654