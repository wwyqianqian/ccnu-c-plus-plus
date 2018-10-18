#include <iostream>
#include <cmath>
using namespace std;

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
        static bool isEven(int test1) {
            if (test1 % 2 == 0) {
                return true;
            } else {
                return false;
            }
        }
        static bool isPrime(int test2) {
            if (test2 == 1) return false;
            for (int i = 2; i <= sqrt(test2); i++) {
                if (test2 % i == 0) {
                    return false;
                }
            }
            return true;
	    }

        bool equal(int test3) const {
            if (test3 == value) {
                return true;
            } else {
                return false;
   	    }
        }
        bool equal(MyInteger&) const {
            return equal(value);
        }
};


int main() {
    cout << "Input your integer: ";
    int myInt;
    cin >> myInt;
	MyInteger A(myInt);
    
    cout << "isEven(FALSE=0 TRUE=1): " << A.isEven(A.getValue()) << endl;
    cout << "isPrime: " << A.isPrime(A.getValue()) << endl;
 
    cout << "input an integer: ";
    int test3;
    cin >> test3;
    cout << "Is this equal to A.value?  :  " << A.equal(test3) << endl;
}


/*
 * output:
 * ~/Desktop  ./a.out                                                                                         1183ms
 * Input your integer: 5
 * isEven(FALSE=0 TRUE=1): 0
 * isPrime: 1
 * input an integer: 3
 * Is this equal to A.value?  :  0
 */
