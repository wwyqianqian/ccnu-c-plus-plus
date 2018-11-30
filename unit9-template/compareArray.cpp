#include <iostream>
using namespace std;

template<class T>
bool compareArray(T arr[], int length) {
    // 为空或者只有一个元素的时候是有序的 (arr.length <= 1)
    // 想想突然发现如果有两个元素的时候，也是有序的！ (于是改成arr.length <= 2)
    if (length <= 2) return true;

    // 如果有有三个或更多元素的时候，最开始的想法是用元素 0 和元素 1 的大小关系来确定我们要检查数组是升序还是降序
    // 然后发现，如果元素 0 和 元素 1 相等咋办？接下来如果 2 和 3 也相等呢？ 于是这里就要先，用个循环把从开头开始相等的元素都跳过
    int i = 0;
    while (i < length - 1 && arr[i] == arr[i + 1]) i++;

    // 如果跑完就到队尾了，那就返回 true (所有元素值都一样)
    if (i == length - 1) return true;

    // 否则的话, 说明 arr[i] ≠ arr[i - 1]，那么较 arr[i] 和 arr[i - 1] 的大小
    bool ifDescend = (arr[i] > arr[i + 1]);
    i++;
    while (i < length - 1 && (arr[i] > arr[i + 1]) == ifDescend) i++;
    return i == length - 1;
}


int main() {
    int list[] = {1, 4, 9, 19, 2, 5, 7}; // 乱序
    int list2[] = {1, 1, 1, 1, 1, 1, 1}; // 全等
    int list3[] = {1, 1, 1, 1, 2, 1}; // 前面全等，后面乱序
    int list4[] = {1, 1, 1, 1, 2, 3}; // 前面全等，后面有序递增
    int list5[] = {9, 9, 9, 8, 7, 6, 5, 4}; // 前面全等，后面有序递减
	
    cout << "0 for false, and 1 for true" << endl;
    cout << "list:" << compareArray<int>(list, sizeof(list) / sizeof(list[0])) << endl; // 0
    cout << "list2:" << compareArray<int>(list2, sizeof(list2) / sizeof(list2[0])) << endl; // 1
    cout << "list3:" << compareArray<int>(list3, sizeof(list3) / sizeof(list3[0])) << endl; // 0
    cout << "list4:" << compareArray<int>(list4, sizeof(list4) / sizeof(list4[0])) << endl; // 1
    cout << "list5:" << compareArray<int>(list5, sizeof(list5) / sizeof(list5[0])) << endl; // 1

    double doubleList[] = {1.4, 1.9, 15.32, 80.4}; // 递增
    double doubleList2[] = {9.0, 8.8, 2.1, 0.4}; // 递减
    cout << "doubleList:" << compareArray<double>(doubleList, sizeof(doubleList) / sizeof(doubleList[0])) << endl; // 1
    cout << "doubleList2:" << compareArray<double>(doubleList2, sizeof(doubleList2) / sizeof(doubleList2[0])) << endl; // 1

    return 0;
}
