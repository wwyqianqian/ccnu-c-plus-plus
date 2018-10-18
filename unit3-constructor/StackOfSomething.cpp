#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef string SElemType;

class StackOfSomething {
    private:
        vector<SElemType> elements;          //Maeda: the type of elements should be consistent
        size_t top_; // the top element's subscript

    public:
        StackOfSomething ():top_(0){}
  
        bool empty() {
	    return !top_;
        }
        //Maeda:for custom the name is hoped to be top, the type returned by top should be reference
        SElemType& top() {               
	    if(empty()) exit(1);        
	    return elements[top_-1];
        }
  
        void push(const SElemType& e) {
	    elements.push_back(e);
	    ++top_;
        }
        bool pop() {
	    if (empty()) {
                return false;
            }
            top_--;
            return true;
        }
        size_t getSize() {
            return top_;
        }
        ~StackOfSomething() {};
    
};

int main() {
    StackOfSomething SoStr;
    SoStr.push(string("a"));
    SoStr.push(string("jiayou"));
    SoStr.push(string("yao"));
    SoStr.push(string("hai"));
    SoStr.push(string("qian"));
    SoStr.push(string("qian"));

    cout << "the size is: " << SoStr.getSize() << endl;
    cout << "the top elements is: " << SoStr.top() << endl;
    while (!SoStr.empty()) {
        cout << SoStr.top() << " ";
        SoStr.pop();
    }
    cout<<endl;
    return 0;
}
