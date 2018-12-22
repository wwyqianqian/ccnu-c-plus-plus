#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;

bool sortBySec(const pair<string, int> &a, const pair<string, int> &b) { 
    return (a.second > b.second); 
} 

int main() {

    set<string> st;
    ifstream sw_f;
    string stStr;
    sw_f.open("stopWords.txt", ios::in);
    if (!sw_f.eof()) {
        while (getline(sw_f, stStr)) {
            st.insert(stStr); 
       }
    }

    map<string, int> mp;
    ifstream f;
    string str;
    f.open("qwq-1.txt", ios::in);
    if (!f.eof()) {
        while (getline(f, str)) {
            auto search = st.find(str);
            if (search == st.end()) {
                ++mp[str];
            }
        }
    }
    f.close();


    map<string, int>::iterator it;
    vector<pair<string, int> > vt;
    vector<pair<string,int> >::iterator vit;

    for (it = mp.begin(); it != mp.end(); it++) {
        vt.push_back(make_pair(it->first, it->second));
    }

    sort(vt.begin(), vt.end(), sortBySec); 

    int i = 0;
    for (vit = vt.begin(), i; i < 20; ++vit, ++i) {
        cout << vit->first << ' ' << vit->second << endl;
    }

   
    return 0;

}


//  ~/Desktop  ./a.out                            652ms  Sat Dec 22 21:52:49 2018
// loss 73
// person 73
// experience 50
// lost 44
// think 33
// process 28
// relationship 26
// way 26
// presence 26
// people 25
// one 24
// grief 24
// someone 23
// grieving 21
// present 20
// would 19
// may 18
// future 18
// differences 16
// often 16