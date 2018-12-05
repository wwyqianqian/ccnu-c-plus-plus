#include <iostream>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    list<int> lists[15000];
    int n;
    cin >> n;
    char command[10];
    int x1, x2, num;
    list<int>::iterator i; // 迭代器

    while (n-- ) {
        cin >> command;
        switch(command[0]) {
        	
            case 'n': // new
                cin >> x1;
                break;

            case 'a': // add 
                cin >> x1 >> num;
                lists[x1].push_back(num);
                break;

            case 'o': // out
                cin >> x1;
                lists[x1].sort();
                for (i = lists[x1].begin(); i != lists[x1].end(); i++) {
                	cout << *i << " "; // 迭代器
                }
                cout << endl;
                break;

            case 'm': // merge
                cin >> x1 >> x2;
                lists[x1].merge(lists[x2]);
                break;    

            case 'u': // unique
                cin >> x1;
                lists[x1].sort(); // 先排序，再 unique()
                lists[x1].unique();
                break;

        }
    }

    return 0;
}


// input:
// 16
// new 1
// new 2
// add 1 1
// add 1 2
// add 1 3
// add 2 1 
// add 2 2
// add 2 3
// add 2 4
// out 1
// out 2
// merge 1 2
// out 1
// out 2
// unique 1
// out 1
// --------------------------------
// output:           Wed Dec  5 17:30:15 2018
// 1 2 3
// 1 2 3 4
// 1 1 2 2 3 3 4


// 1 2 3 4
