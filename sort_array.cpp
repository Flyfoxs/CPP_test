#include <iostream>
using namespace std;
int* sort_insert(int input[], int n){
    int* output = input;
    // 假设这里有排序逻辑，将input数组排序后存入output数组
    return output;
}

int main() {
    int input[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(input) / sizeof(input[0]);
    int* sorted = sort_insert(input, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << sorted[i] << " ";
    }
    cout << endl;
    // 使用sorted数组
    // delete[] sorted; // 释放动态分配的内存
    return 0;
}
