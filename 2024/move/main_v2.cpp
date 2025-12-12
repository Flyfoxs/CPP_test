#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100000;
long long x[MAXN];
long long b[MAXN];

int main() {
    // 文件重定向，提交时请取消注释
    freopen("move.in", "r", stdin);
    // freopen("move.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);                     // 将电子狗位置排序
    for (int i = 0; i < n; ++i) {
        b[i] = x[i] - i;                // 计算 b 序列
    }
    sort(b, b + n);                     // 排序 b 以方便找中位数
    long long mid = b[n / 2];           // 取中位数（上中位数）
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(b[i] - mid);         // 计算距离和
    }
    cout << ans << endl;
    return 0;
}