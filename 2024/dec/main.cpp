#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> m_list;
vector<vector<int>> dp;

//9439. 【2024年庐阳区初中区赛】减少毒素（dec）(5) 60分

//dp[i][j] 表示前i个毒素, 使用j种物质, 减少的毒素值
int main() {
    freopen("dec.in", "r", stdin);
    // freopen("dec.out", "w", stdout);
    int n, m; // n: 毒素的数量, m: 物质种类
    cin >> n >> m;
    m_list.resize(m+1);
    dp.resize(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        m_list[i] = make_pair(a, b);
    }

    for(int i=1; i<=n; i++){//毒素的数量
        for(int j=1; j<=m; j++){//物质种类
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            for(int k=0; k*m_list[j].first<=i; k++){//物质j的份数
                int cur_cost = k*(m_list[j].first-m_list[j].second);
                dp[i][j] = max(dp[i][j], dp[i-cur_cost][j-1] + cur_cost);
            }
        }
    }
 
    cout << n-dp[n][m] << endl;

    return 0;
    
}

/*
g++-14 -o main.out main.cpp && ./main.out
*/