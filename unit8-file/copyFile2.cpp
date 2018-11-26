#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
    	cout << "File name missing!" << endl;
    	return 0;
    }
    ifstream inFile(argv[1], ios::binary|ios::in); // 读取打开的文件
    if (!inFile) {
    	cout << "Source File open error!" << endl;
    	return 0;
    }
    ofstream outFile(argv[2], ios::binary|ios::out); // 新建要写入的文件
    if (!outFile) {
        cout << "New File open error!" << endl;
        inFile.close(); // 之前打开的要关闭哦
        return 0;
    }
    
    char c;
    while (inFile.get(c)) { // 每次读取一个字节
    	outFile.put(c);
    }
    outFile.close();
    inFile.close();

    return 0;
}