#include <iostream>
using namespace std;

class MyString {
private:
    char * my_data; // 和 27 行保持一致，所以加了个空格

public:
    MyString(): my_data((char *)"") {}; // 显式类型转换，C++ 里 string 是固定长度的，而 char * 是 固定长度的

    MyString(const char *cString);

    char at(int index) const; // index 默认下标，不是位置了

    int length() const;

    void clear();

    bool empty() const;

    int compare(const MyString &s) const;

    int compare(int index, int n, MyString &s) const;

    void copy(char s[], int index, int n) const;

    char * data() const;

    int find(char ch) const;

    int find(char ch, int index) const;

    virtual ~MyString() {
        delete[] my_data;
    };
    
};

MyString::MyString(const char *cString) {
    if (cString == nullptr) {
        my_data = new char[1];
        *my_data = '\0';
    } else {
        int len_str = strlen(cString);
        my_data = new char[len_str + 1];
        strcpy(my_data, cString);
    }
}

char MyString::at(int index) const {
    if (index < 0 || index > strlen(my_data)) { // .at() 会检查有没有越界，所以这里要多一个判断
        cout << "out_of_range" << endl;
        return '\0'; // 这种情况下也最好给函数一个返回值
    } else {
        return my_data[index];
    }
}

int MyString::length() const {
    return strlen(my_data);
}

void MyString::clear() { // clear() 之后，size() 变成 0，capacity() 不变
    int len_str = strlen(my_data);
    delete[] my_data;
    my_data = new char[len_str + 1];
    my_data[0] = '\0';
}

bool MyString::empty() const {
    return length() == 0;
}

int MyString::compare(const MyString &s) const { // 数据结构写过类似的 int compare(List A, List B) 函数
    int i = 0;
    while (i < this->length() && i < s.length()) {
        if (this->my_data[i] < s.my_data[i]) {
            return -1;
        } else if (this->my_data[i] > s.my_data[i]) {
            return 1;
        } else {
            i++;
        }
    }
    if (this->length() == s.length()) {
        return 0;
    } else if (this->length() < s.length()) {
        return -1;
    } else {
        return 1;
    }
}

int MyString::compare(int index, int n, MyString &s) const { // 膜改
    //int i = index; int j = 0;
    for (int i = index, j = 0; i < n + index && j < s.length(); ) { // 直接把赋值放到 for (; ;) 括号里的第一个位置
        if (this->my_data[i] < s.my_data[j]) {
            return -1;
        } else if (this->my_data[i] > s.my_data[j]) {
            return 1;
        } else {
            i++;
            j++;
        }
    }
    if (n == s.length()) {
        return 0;
    } else if (n < s.length()) {
        return -1;
    } else {
        return 1;
    }
}

void MyString::copy(char s[], int index, int n) const {
    if (n + index > this->length()) {
        cout << "out of range!" << endl;
    } else {
        //int i = index; int j = 0;
        for (int i = index, j = 0; i < n + index; i++, j++) { // 同上，或者写成 int i, j; 然后 for 里面写 for (i = index, j = 0)
            s[j] = this->my_data[i];
        }
    }
}

char * MyString::data() const {
    return this->my_data;
}

int MyString::find(char ch) const {
    for (int i = 0; i < this->length(); i++) {
        if (this->my_data[i] == ch) {
            return i; // 返回的下标
        }
    }
    cout << "string::npos" << endl;
    return -1;
}

int MyString::find(char ch, int index) const {
    if (index > this->length() || index < 0) {
        cout << "out of range" << endl;
        return -1;// 这种情况也需要个返回值鸭
    } else {
        for (int i = index; i < this->length(); i++) {
            if (this->my_data[i] == ch) {
                return i;
            }
        }
        cout << "string::npos" << endl;
        return -1;
    }
}


int main() {
    MyString s("abcdefghijk");

    cout << "This is string s's data: " << s.data() << endl;

    cout << "s.length() : " << s.length() << endl;
    cout << "s.empty() : " << s.empty() << endl;
    cout << "s.at(2) : " << s.at(2) << endl;
    cout << endl;

    MyString ss("abcdefg");
    cout << "This is string ss's data: " << ss.data() << endl;
    cout << "s compare to ss: " << s.compare(ss) << endl;
    cout << "s compare to index 5 of ss: " << s.compare(0, 5, ss) << endl;
    cout << endl;

    MyString sss("abcdefghijk");
    cout << "This is string sss's data: " << sss.data() << endl;
    cout << "s compare to sss: " << s.compare(sss) << endl;
    cout << "s compare to index 11 of sss: " << s.compare(0, 11, sss) << endl;
    cout << endl;

    char ch[] = {0};
    s.copy(ch, 1, 5);
    cout << "This is a part of copy of string s: " << ch << endl;
    cout << endl;

    cout << "Find char d's position in string s: " << s.find('d') << endl;
    cout << "Find char d's position in string s: " << s.find('d', 6) << endl;


    s.clear();
    cout << "After clear: s.empty() " << s.empty() << endl;
}


//  ~/Desktop  ./a.out                            353ms  Thu Nov 15 00:33:17 2018
// This is string s's data: abcdefghijk
// s.length() : 11
// s.empty() : 0
// s.at(2) : c

// This is string ss's data: abcdefg
// s compare to ss: 1
// s compare to index of ss: -1

// This is string sss's data: abcdefghijk
// s compare to sss: 0
// s compare to index of sss: 0

// This is a part of copy of string s: bcdef

// Find char d's position in string s: 3
// Find char d's position in string s: string::npos
// -1
// After clear: s.empty() 1