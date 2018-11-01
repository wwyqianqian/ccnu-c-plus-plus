#pragma once

template <typename T>
struct LinkedList {
    T * val;
    LinkedList<T> * next;

    LinkedList(T * v): val(v), next(nullptr) {}
};