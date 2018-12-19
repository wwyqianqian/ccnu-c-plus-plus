#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int a[8] = {6, 5, 14, 23, 2, 9, 87, 10};
    sort(a + 1, a + 7, compare);

    for (int i = 0; i < 8; ++i) {
        cout << a[i] << ",";
    }
    return 0;
}

// output:
// ~/Desktop  ./a.out                                   Wed Dec 12 16:38:08 2018
// 6,87,23,14,9,5,2,10,⏎