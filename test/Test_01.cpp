#include <iostream>
#include <vector> // 用于动态数组
using namespace std;

// 打印二维数组
void printArray(const vector<vector<int> >& array) {
    for (const auto& row : array) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// 判断是否越界或已填充
bool isOutOfBoundOrFilled(const vector<vector<int> >& array, int i, int j, int rows, int cols) {
    return i < 0 || i >= rows || j < 0 || j >= cols || array[i][j] != -1;
}

int main() {
    int rows = 4, cols = 4; // 可以通过用户输入动态调整

    // 初始化二维数组，初始值为 -1
    vector<vector<int> > array(rows, vector<int>(cols, -1));

    // 使用push_back添加方向
    vector<pair<int, int> > directions;
    directions.push_back(make_pair(0, 1));  // 右
    directions.push_back(make_pair(1, 0));  // 下
    directions.push_back(make_pair(0, -1)); // 左
    directions.push_back(make_pair(-1, 0)); // 上

    int totalElements = rows * cols;
    int dirIndex = 0, i = 0, j = 0;

    for (int num = 1; num <= totalElements; ++num) {
        array[i][j] = num; // 填充当前元素

        // 计算下一个位置
        int nextI = i + directions[dirIndex].first;
        int nextJ = j + directions[dirIndex].second;

        // 检查是否需要改变方向
        if (isOutOfBoundOrFilled(array, nextI, nextJ, rows, cols)) {
            dirIndex = (dirIndex + 1) % 4; // 顺时针改变方向
            nextI = i + directions[dirIndex].first;
            nextJ = j + directions[dirIndex].second;
        }

        // 更新坐标
        i = nextI;
        j = nextJ;
    }

    // 打印结果
    printArray(array);

    return 0;
}
