// req output: 
// A::Fun
// C::Do

#include <iostream>
using namespace std;

class A {
private:
    int nVal;
public:
    void Fun() {
        cout << "A::Fun" << endl;
    };

    virtual void Do() {
        cout << "A::Do" << endl;
    }
};

class B: public A {
public:
    virtual void Do() {
        cout << "B::Do" << endl;
    }
};

class C: public B {
public:
    void Do() {
        cout << "C::Do" << endl;
    }
    void Fun() {
        cout << "C::Fun" << endl;
    }
};

void Call(B &p) {
    p.Fun();
    p.Do();
}


int main() {
    C c;
    Call(c);
    return 0;
} 

// ~/Desktop  ./a.out                            316ms  Wed Nov 14 16:27:49 2018
// A::Fun
// C::Do
