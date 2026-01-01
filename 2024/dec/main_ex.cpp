#include <bits/stdc++.h>
using namespace std;

// 9439. 【2024年庐阳区初中区赛】减少毒素（dec）(5) 100 分
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m), d(m); // a: 初始毒素, b: 剩余毒素, d: 净减少量
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        d[i] = a[i] - b[i];  // 净减少量
    }

    // dp[x] 表示是否可以减少到 x 毒素
    vector<bool> dp(n + 1, false);
    dp[n] = true;  // 初始毒素

    for (int x = n; x >= 0; x--) {
        if (!dp[x]) continue;
        for (int i = 0; i < m; i++) {
            if (x >= a[i]) {
                int nx = x - d[i];
                if (nx >= 0)
                    dp[nx] = true;
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        if (dp[x]) {
            cout << x << "\n";
            break;
        }
    }

    return 0;
}


/*
g++-14 -o main.out main_ex.cpp && ./main.out
*/