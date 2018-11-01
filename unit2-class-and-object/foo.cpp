// 约瑟夫环问题 - n 个小孩围城一圈 从第 w 个开始从 1 开始报数 每次报到第 s 个出列
// 然后从下一个人开始再从 1 开始报数 求出列顺序
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
    string exit_order = "出列顺序:";

    while(len > 0){
        for(int i = 1; i < S; ++i){
            cout << "小孩 " << it->val->code << " 报数: " << i << endl;;
            it = it->next;
            last = last->next;
        }
        tmp = it;
        cout << "小孩 " << tmp->val->code << " 报数: " << S << "! 出列"<< endl;
        exit_order += " " + to_string(tmp->val->code);
        it = tmp->next;
        last->next = it;
        delete tmp->val;
        delete tmp;
        len--;
        // 下面这两行导致多跳了一个人没报数
        //it = it->next;
        //last = last->next;
    }
    cout << exit_order << endl;
    return 0;
}