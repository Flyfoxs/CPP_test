#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2e5+5;

/*
dp[cnt][x] 的含义：
使用 cnt 次“拼接/操作”后，是否可以得到值 x
取值含义：
-1 : 不可达
 i : 只能由第 i 个序列唯一得到
-2 : 可以由多个序列得到（不唯一）
*/
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    // dp 数组，cnt 最大 100，x 最大 N
    vector<vector<int>> dp(100 + 1, vector<int>(N, -1));

    // s[i] 表示第 i 个序列
    vector<vector<int>> s(n + 1);

    // 初始状态：cnt = 0 时，只能得到值 1，标记为 -2（表示“公共起点”）
    dp[0][1] = -2;

    // 读入每个序列
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        s[i].resize(len);
        for (auto &v : s[i])
            cin >> v;
    }

    // cnt 表示使用的操作次数
    for (int cnt = 1; cnt <= 100; cnt++) {

        // 枚举每一个序列
        for (int i = 1; i <= n; i++) {

            // lst：记录上一次“合法起点”的位置
            int lst = -1; //不可达

            // 枚举序列中的每一个元素
            for (int j = 0; j < (int)s[i].size(); j++) {

                int x = s[i][j];

                /*
                情况 1：
                如果之前有一个合法起点 lst，
                并且当前 j 与 lst 的距离不超过 k，
                那么可以从 s[i][lst] 过渡到 x
                */
                if (lst != -1 && (j - lst + 1 <= k)) {
					//lst 可达，且距离不超过 k
                    // 必须保证 cnt-1 时 s[i][lst] 是可达的
                    // 并且不是来自同一个序列 i（避免重复使用同一序列）
                    if (dp[cnt - 1][s[i][lst]] != -1 &&
                        dp[cnt - 1][s[i][lst]] != i) {

                        // 如果 cnt 次下 x 还没被标记，标记为来自序列 i
                        if (dp[cnt][x] == -1)
                            dp[cnt][x] = i;

                        // 如果已经被别的序列标记过，说明不唯一
                        else if (dp[cnt][x] != i)
                            dp[cnt][x] = -2;
                    }
                }

                /*
                情况 2：
                判断当前 x 是否可以作为新的起点
                即：cnt-1 时 x 是可达的，且不是来自当前序列 i
                */
                int v = dp[cnt - 1][x];
                if (v != -1 && v != i) {
                    lst = j;
                }
            }
        }
    }

    // 回答查询
    // 询问：使用 r 次操作，是否可以得到值 c
    while (q--) {
        int r, c;
        cin >> r >> c;
        // dp[r][c] != -1 表示可达
        cout << ((dp[r][c] != -1) ? 1 : 0) << "\n";
    }
}

int main() {
    freopen("chain.in", "r", stdin);
    // freopen("chain.out", "w", stdout);

    int T = 1;
    cin >> T;
    while (T--)
        solve();
}

/**

 g++-14 -o main.out main_ex3.cpp && ./main.out

 */