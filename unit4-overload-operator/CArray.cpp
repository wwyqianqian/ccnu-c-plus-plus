#include <iostream>
#include <cstring>
using namespace std;

class CArray {
    private:
        int size;
        int *p;
    public:
    	CArray(int a = 0);
        CArray(CArray & ca);
        ~CArray();
        CArray &operator=(const CArray &ca);
        void push_back(int x);
        int length() {
            return size;
        }
        int &operator[] (int j) {
            return p[j];
        }
};

CArray::CArray(int a) {
	size = a;
    if (a == 0) {
        p = nullptr;
    } else {
        p = new int[a];
    }
}

CArray::CArray(CArray &ca) {
    if (!ca.p) {
        p = nullptr;
        size = 0;
        return;
    } else {
        p = new int[ca.size];
        size = ca.size;
        memcpy(p, ca.p, sizeof(int) * ca.size);
    }
}

CArray::~CArray() {
    if (p) {
        delete [] p;
    }
}

void CArray::push_back(int x) {
    if (p) {
        int *np = new int[size + 1];
        memcpy(np, p, sizeof(int) * size);
        delete [] p;
        p = np;
    } else {
        p = new int[1];
    }
    p[size++] = x;
}

CArray &CArray::operator=(const CArray &ca) {
    if (p == ca.p) {
        return *this;
    }
    if (ca.p == nullptr) {
        if (p != nullptr) {
            delete [] p;
        }
        p = nullptr;
        size = 0;
        return *this;
    }
    if (ca.size > size) {
        if (p) {
            delete [] p;
        }
        p = new int[ca.size];
    }
    memcpy(p, ca.p, sizeof(int) * ca.size);
    size = ca.size;
    return *this;
}

int main() {
    CArray a;
    for (int i = 0; i < 5; ++i) {
        a.push_back(i); 
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); ++i) {
        cout << a2[i] << " ";
    }
    a2 = a3;
    for (int i = 0; i < a2.length(); ++i) {
        cout << a2[i] << " ";
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); ++i) {
        cout << a4[i] << " ";    
    }
    return 0;
}


//output:
//  ~/Desktop  ./a.out                                                       338ms  Wed Oct 31 22:37:21 2018
// 0 1 2 3 4
// 0 1 2 100 4 ⏎
