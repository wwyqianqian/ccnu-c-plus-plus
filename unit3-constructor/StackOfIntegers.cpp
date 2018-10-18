#include <iostream>
using namespace std;
typedef int SElemType;

class StackOfIntegers {
    private:
        int elements[100];
        int top; // the top element's subscript
        int size; // max size

    public:
        StackOfIntegers(int myTop, int myStackSize) {
            top = myTop;
            size = myStackSize;
           
        }
        bool empty() {
            if (top == -1) {
                return true;
            } else {
                return false;
            }
        }
        int peek() {
            if (top == -1) {
                return 0;
            }
            int e = 0;
            e = elements[top];
            return e;
        }
        bool push(SElemType e) {
            if (top == size - 1) {
                return false;
            }
            elements[++top] = e;
            return true;
        }
        bool pop() {
            if (top == -1) {
                return false;
            }
            top--;
            return true;
        }
        int getSize() {
            return top + 1;
        }
        ~StackOfIntegers() {};
    
};

int main() {
    StackOfIntegers SoI(-1, 100);
    SoI.push(1);
    SoI.push(1);
    SoI.push(4);
    SoI.push(5);
    SoI.push(1);
    SoI.push(4);

    cout << "the size is: " << SoI.getSize() << endl;
    cout << "the top elements is: " << SoI.peek() << endl;
    while (!SoI.empty()) {
        cout << SoI.peek() << " ";
        SoI.pop();
    }
}


//  ~/Desktop  ./a.out                           
// the size is: 6
// the top elements is: 4
// 4 1 5 4 1 1 ⏎