#include <bits/stdc++.h>
using namespace std;

// 5846. [CSP-J 2022] 上升点列（point）

struct Point {
    long long x, y;
};

int main() {
    freopen("point.in", "r", stdin);
    // freopen("point.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<Point> pts(n+1);
    /**
    dp[i][j]:
    以第 i 个点作为结尾，
    使用了 j 个“补点”，
    能形成的最大路径长度（点数）
    */
    vector<vector<long long >> dp(n+1, vector<long long >(k+1, -1));

    
    for (int i = 1; i <= n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin()+1, pts.end(), [](auto &a, auto &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    // cout << "After sort:" << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << pts[i].x << " " << pts[i].y << endl;
    // }

    for(int i=1;i<=n;i++){//To
        // 单独选这个点，不用补点
        dp[i][0] = 1;
        for(int j=1;j<i;j++){//From
            if(pts[i].x >= pts[j].x && pts[i].y >= pts[j].y){
                // cout << "(" << pts[i].x << ", " << pts[i].y << ") <- (" << pts[j].x << ", " << pts[j].y << ")" << endl;
                long long dx = pts[i].x - pts[j].x;
                long long dy = pts[i].y - pts[j].y;
                long long need = pts[i].x - pts[j].x + pts[i].y - pts[j].y - 1;

                if(need > k) continue;

                for(int used = need; used <= k; used++){
                    if(dp[j][used - need] == -1) continue; //检查dp[j] 之前是不是可达

                    dp[i][used] = max(dp[i][used], dp[j][used - need] + dx + dy);
                }
            }
        }
    }

    long long ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            ans = max(ans, dp[i][j] + k - j);
        }
    }
    cout << ans << endl;

    return 0;

}//main end


/**
g++-14 -o main.out main_ex.cpp && ./main.out
*/