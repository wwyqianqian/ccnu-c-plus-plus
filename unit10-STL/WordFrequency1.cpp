#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool sortBySec(const pair<string, int> &a, const pair<string, int> &b) { 
    return (a.second > b.second); 
} 

int main() {
    map<string, int> mp;
    string str;
    while (getline(cin, str)) { // mac OS 按 control + d 键终止输入（即 EOF）。
        ++mp[str];      
    }   
    cout << endl;

    map<string, int>::iterator it;
    vector<pair<string, int> > vt;
    vector<pair<string,int> >::iterator vit;

    for (it = mp.begin(); it != mp.end(); it++) {
        vt.push_back(make_pair(it->first, it->second));
    }

    sort(vt.begin(), vt.end(), sortBySec); 
    for(vit = vt.begin(); vit != vt.end(); ++vit) {
        cout << vit->first << ' ' << vit->second << endl;
    }

    return 0;

}


//  ~/Desktop  ./a.out                            433ms  Wed Dec 19 19:04:00 2018
// this
// is
// ok
// this
// plus
// that
// is
// plus
// plus
// ^D
// plus 3
// is 2
// this 2
// ok 1
// that 1