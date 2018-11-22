#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Enter source file name: ";
    string inputFileName;
    cin >> inputFileName;
    cout << "Enter target file name: ";
    string outputFileName;
    cin >> outputFileName;

    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    if (input.fail()) {
        cout << "This file does not exist!";
        return 0;
    }
    
    char ch = input.get();
    while(!input.eof()) {
        output.put(ch);
        ch = input.get();
    }

    input.close();
    output.close();
    cout << "Finished" << endl;

    return 0;

}