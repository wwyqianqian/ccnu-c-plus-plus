#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s) {
    int len_s = s.length();
    string s_cp("");
    for (int i = len_s - 1; i >= 0; i--) {
        s_cp += s.at(i);
    }
    
    // if (s.compare(s_cp) == 0) {
    //     return true;
    // } else {
    //     return false;
    // }
    
    return !s.compare(s_cp);
}

int main() {
    string s("abcccba");
    string ss("abccccba");
    string sss("abcddddd");

    cout << s << "  is palindrome (1 for true and 0 for false) : " << isPalindrome(s) << endl;
    cout << ss << "  is palindrome : " << isPalindrome(ss) << endl;
    cout << sss << "  is palindrome : " << isPalindrome(sss) << endl;
    
    return 0;
}

//  ~/Desktop  ./a.out                            392ms  Wed Nov 14 17:34:00 2018
// abcccba  is palindrome (1 for true and 0 for false) : 1
// abccccba  is palindrome : 1
// abcddddd  is palindrome : 0