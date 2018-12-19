#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {   
    multiset<int> mtst;
    set<int> st;
    char commend[20];
    int i, n, num;
    multiset<int>::iterator it;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> commend >> num;
        switch (commend[1]) {
            case 'd': // add 
                mtst.insert(num);
                st.insert(num);
                cout << mtst.count(num) << endl; // 输出个数
                break;                
            case 'e': // delete 删除与 num 相同的元素
                cout << mtst.count(num) << endl; // 输出个数
                mtst.erase(num); // del
                break;
            case 's': // ask 先输出 0/1 查找是否在里面
                if (st.find(num) == st.end()) {
                    cout << "0 ";
                    cout << mtst.count(num) << endl;
                } else {
                    cout << "1 ";
                    cout << mtst.count(num) << endl;
                }
                break;
        }
    }

    return 0;
}

//  ~/Desktop  ./a.out                           386ms  Wed Dec 12 17:23:11 2018
// 7
// add 1
// add 1
// ask 1
// ask 2
// del 2
// del 1
// ask 1

// 1
// 2
// 1 2
// 0 0
// 0
// 2
// 1 0