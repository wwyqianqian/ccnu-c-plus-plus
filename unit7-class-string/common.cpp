#include <iostream>
#include <string>
using namespace std;

string commonChars(const string &S1, const string &S2) {
    int len_s1 = S1.length();
    string out;
	
    for (int i = 0; i < len_s1; ++i) {
        int pos = 0;
        pos = S2.find(S1.at(i));
        if (pos != string::npos) {
            out += S1.at(i);
        }
    }
    return out;
}

int main () {
    string S1("abcd");
    string S2("aecaten");

    cout << commonChars(S1, S2);
    return 0;
}

//  ~/Desktop  ./a.out                            320ms  Wed Nov 14 17:11:23 2018
// ac⏎
