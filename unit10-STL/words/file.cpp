#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main () {
    ifstream fin;
    fin.open("file.txt", ios::in);

    vector<string> v;
    string tmp;

    while (fin >> tmp) {
        v.push_back(tmp);
    }


    ofstream fout;
    fout.open("words.txt", ios::out);

    for (auto x : v) {
        fout << x << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
