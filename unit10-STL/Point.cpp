#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Rule1 {
    bool operator() (const int &a, const int &b) {
        if (a % 10 == b % 10) { // 个位数相同，大的在前面
        	return a > b;
        } else {
        	return (a % 10 < b % 10); // 个位数从小到大排
        }
    }
};

struct Rule2 {
    bool operator() (const Point &a, const Point &b) {
        int x1 = a.x * a.x + a.y * a.y;
        int x2 = b.x * b.x + b.y * b.y; 
        if (x1 == x2) { // 距离相同
            if (a.x == b.x) { // x 座标相同
                return a.y < b.y; // 按照 y 座标小到大
            } else {
                return a.x < b.x;
            }
        } else {
            return (x1 < x2); // 距离从小到大
        }
    }
};

int main() {
    int a[8] = {6, 5, 55, 23, 3, 9, 87, 10};
    sort(a, a + 8, Rule1());
    for (int i = 0; i < 8; ++i) {
    	cout << a[i] << ",";
    }
    cout << endl;

    Point ps[8] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {2, 0}, {-2, 0}};
    sort(ps, ps + 8, Rule2());
    for (int i = 0; i < 8; ++i) {
    	cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
    }

    return 0;
}


// output
//  ~/Desktop  ./a.out                           409ms  Wed Dec 12 17:08:03 2018
// 10,23,3,55,5,6,87,9,
// (-1,0)(0,-1)(0,1)(1,0)(1,-1)(1,1)(-2,0)(2,0)⏎
