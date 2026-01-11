#include <bits/stdc++.h>
using namespace std;

// 5846. [CSP-J 2022] 上升点列（point）

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // 1️⃣ 按坐标排序，保证 DP 是 DAG
    sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    // 2️⃣ 初始化 DP 表
    /*
    dp[i][j]:
    以第 i 个点作为结尾，
    使用了 j 个“补点”，
    能形成的最大路径长度（点数）
    */
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    int ans = 0;

    // 3️⃣ 枚举结尾点 i
    for (int i = 0; i < n; i++) {//TO

        // 单独选这个点，不用补点
        dp[i][0] = 1;

        // 4️⃣ 尝试从之前的点 p 转移过来
        for (int p = 0; p < i; p++) {//From

            long long dx = pts[i].x - pts[p].x;
            long long dy = pts[i].y - pts[p].y;

            // 不能单调走
            if (dx < 0 || dy < 0) continue;

            // 从 p 走到 i 需要补的点数
            long long need = dx + dy - 1;
            if (need > k) continue;

            // 5️⃣ 枚举补点使用量
            // cout << "i=" << i << " p=" << p << " dx=" << dx << " dy=" << dy << " need=" << need << endl;
            for (int used = need; used <= k; used++) {
                if (dp[p][used - need] == -1) continue; //检查dp[p] 之前是不是可达, 是否可以和当前的p->i形成上升点列
                // printf("i=%d p=%d used=%d need=%d dp[p][%d]=%d\n", i, p    , used, need, used - need, dp[p][used - need]);
                // cout << "i=" << i << " used=" << used << " need=" << need << " dp[p][used - need]=" << dp[p][used - need] << endl;

                dp[i][used] = max(
                    dp[i][used], // -1 by default
                    dp[p][used - need] + (int)(dx + dy) //dx + dy就是从p到i的距离
                );
            }
        }

        // 6️⃣ 更新答案
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[i][j]+k-j); //k-j 剩余没有用完的自由点
        }
    }

    // 7️⃣ 全部使用补点（不选已有点）
    ans = max(ans, k + 1);

    cout << ans << "\n";
    return 0;
}

/**

g++-14 -o main.out main.cpp && ./main.out
*/