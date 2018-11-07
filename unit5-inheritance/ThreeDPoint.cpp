#include <iostream>
#include<cmath>
using namespace std;

class MyPoint {
protected:
    double x;
    double y;
public:
    MyPoint(): x(0), y(0) {};
    MyPoint(double _x, double _y) {
        x = _x;
        y = _y;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double distance(const MyPoint & mp) const {
        int xx = abs(x - mp.x);
        int yy = abs(y - mp.y);
        return sqrt(xx * xx + yy * yy);
    }
    ~MyPoint() {};
	
};

class ThreeDPoint : public MyPoint { 
private:
    double z;
public:   
    ThreeDPoint(): z(0) {}; 
    ThreeDPoint(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    double getZ() {
        return z;
    }
    double distance(const ThreeDPoint & tdp) const {
        int xxx = abs(x - tdp.x);
        int yyy = abs(y - tdp.y);
        int zzz = abs(z - tdp.z);
        return sqrt(xxx * xxx + yyy * yyy + zzz * zzz);
    }
    ~ThreeDPoint() {};
	
};

int main() {
    MyPoint MP; // MP(0, 0)
    MyPoint MP2(3, 4);
    cout << MP.distance(MP2) << endl;

    ThreeDPoint TDP; // TDP(0, 0, 0)
    ThreeDPoint TDP2(10, 30, 25.5);
    cout << TDP.distance(TDP2) << endl;

    return 0;

}


//  ~/Desktop  ./a.out                            351ms  Wed Nov  7 16:50:43 2018
// 5
// 40.3113