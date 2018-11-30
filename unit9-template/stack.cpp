#include <iostream>
#include <string>
using namespace std;

template<class T>
class Stack {
public:
    Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;

private:
    T elements[100];
    int size;
};

template<class T>
Stack<T>::Stack() {
    size = 0;
}

template<class T>
bool Stack<T>::empty() const {
    return size == 0;
}

template<class T> 
T Stack<T>::peek() const {
    return elements[size - 1];
}

template<class T>
void Stack<T>::push(T value) {
    elements[size++] = value;
}

template<class T>
T Stack<T>::pop() {
    return elements[--size];
}

template<class T>
int Stack<T>::getSize() const {
    return size;
}


template<class T>
void printStack(Stack<T> &Stack) {
    while(!Stack.empty()) {
        cout << Stack.pop() << " ";
    }
    cout << endl;
}

int main() {
    Stack<int> intStack;
    for (int i = 0; i < 10; i++) {
        intStack.push(i);
    }
    printStack(intStack);


    Stack<string> stringStack;
    stringStack.push("!");
    stringStack.push("C++");
    stringStack.push("Hello");
    printStack(stringStack);

    return 0;
}


//  ~/Desktop  ./a.out                                                 335ms  Wed Nov 28 16:21:39 2018
// 9 8 7 6 5 4 3 2 1 0
// Hello C++ !