#include <iostream>
#include <cmath>
using namespace std;
typedef int SElemType;

class MyInteger {
    private: 
        int value;
    public:
        MyInteger(int va = 0) {
            value = va;
        }
        int getValue() {
            return value;
        }
        static bool isPrime(int test2) {
            if (test2 == 1 || test2 == 2) return true;
            for (int i = 2; i <= sqrt(test2); i++) {
                if (test2 % i == 0) {
                    return false;
                }
            }
            return true;
	    }
};

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

void getDivision(int x, StackOfIntegers stack) {
    int i = 2;
    while (i <= x) {
    	if (x % i == 0) {
    		stack.push(i);
            x = x / i;
            cout << "qwqqwq" << stack.peek() << endl;
    	} else {
    		i++;
    	}
    }

    // int root = sqrt(x);
    // int i = 2;
    // while (i < root) {
    // 	if (x % i == 0 && MyInteger::isPrime(i)) {
    // 		stack.push(i++);
    // 	}
    // }

    while (!stack.empty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
}

int main() {
	cout << "Input your integer: ";
    int myInt;
    cin >> myInt;
	MyInteger A(myInt);
	StackOfIntegers stack(-1, 100);

	getDivision(A.getValue(), stack);

}


//  ~/Desktop  ./a.out                            
// Input your integer: 8
// 2 2 2 ⏎    

// ~/Desktop  ./a.out                            
// Input your integer: 120
// 5 3 2 2 2 ⏎