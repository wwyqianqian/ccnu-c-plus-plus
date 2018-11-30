#include <iostream>
#include <string>
using namespace std;

template <class T>
T ArraySum(T *p1,T *p2) {
    T a = *p1++;
    while (p1 != p2) {
        a += *p1++;
    }
    return a;
}


int main() {
    string array[4] = {"Tom", "Jack", "Mary", "John"};
    cout << ArraySum(array, array + 4) << endl;

    int a[4] = { 1, 2, 3, 4};
    cout << ArraySum(a, a + 4) << endl;

    return 0;
}


//  ~/Desktop  ./a.out                                                                    409ms  Wed Nov 28 16:40:18 2018
// TomJackMaryJohn
// 10