// n个小孩 s个出列 w开始
#include <iostream>
#include "linked_list.hpp"
#include <cassert>

using namespace std;

struct Student {
    int code;

    Student(int c):code(c) {}
};

int main(int, char**){
    int N = 10;
    int W = 1;
    int S = 5;

    cout << "N: " << N << " W: " << W << " S: " << S <<endl;
    LinkedList<Student> * students = nullptr;
    LinkedList<Student> * it_head = nullptr;
    LinkedList<Student> * it_last = nullptr;

    for(int i = 1; i <= N; ++i){
        auto student = new Student(i);
        if(!students){
            students = new LinkedList<Student>(student);
            it_head = students;
            it_last = it_head;
            it_head->next = students;
        }else{
            auto new_node = new LinkedList<Student>(student);
            new_node->next = students;
            it_head->next = new_node;
            it_head = new_node;
            it_last = it_head;
        }
    }

    auto it = students;
    auto last = it_last;

    // Set start point to the Wth student
    for(int i = 1; i < W; ++i){
        it = it->next;
        last = last->next;
    }

    int len = N;

    assert(last->next == it);

    auto tmp = it;

    while(len > 0){
        for(int i = 1; i < S; ++i){
            cout << it->val->code << ": " << i << endl;;
            it = it->next;
            last = last->next;
        }
        tmp = it;
        cout << " Removed: " << tmp->val->code << endl;
        it = tmp->next;
        last->next = it;
        delete tmp->val;
        delete tmp;
        len--;
        it = it->next;
        last = last->next;
    }

    return 0;
}