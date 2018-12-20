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
    f.open("article.txt", ios::in);
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
    for (vit = vt.begin(); vit != vt.end(); ++vit) {
        cout << vit->first << ' ' << vit->second << endl;
    }

   
    return 0;

}

