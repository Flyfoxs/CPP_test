#include <bits/stdc++.h>
using namespace std;
// 9274：[CSP-J 2024] 小木棍（sticks）50 分
// 每个数字0-9需要的小木棍数量
const int stick_cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// 动态规划求解最小数字
string solve(int n) {
    // dp[i]表示使用i根木棍能拼出的最小数字的字符串形式
    // 初始化为"#"表示不可达
    vector<string> dp(n + 1, "#");
    
    // 初始化：0根木棍可以拼出空字符串（作为起点）
    dp[0] = "";
    
    for (int i = 1; i <= n; i++) {
        for (int digit = 0; digit <= 9; digit++) {
            int cost = stick_cost[digit];
            // 如果当前木棍数足够拼这个数字，且之前的状态可达
            // cout << "i=" << i << " digit=" << digit << " cost=" << cost << " dp[i - cost]=" << dp[i - cost] << endl;
            if (i >= cost && dp[i - cost] != "#") {
                string new_num = dp[i - cost] + to_string(digit);
                
                // 如果是第一个数字，不能是0（避免前导0）
                if (dp[i - cost] == "" && digit == 0) {
                    continue;
                }
                
                // 如果当前状态不可达，或者新数字更小，则更新
                if (dp[i] == "#" || 
                    new_num.length() < dp[i].length() ||
                    (new_num.length() == dp[i].length() && new_num < dp[i])) {
                    // cout << "i=" << i << " digit=" << digit << ", old_num=" << dp[i] << ", new_num=" << new_num << endl;
                    dp[i] = new_num;
                }
            }
        }
        // cout << endl;
    }
    
    return dp[n] == "#" ? "-1" : dp[n];
}

int main() {

    freopen("sticks.in", "r", stdin);
    // freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    
    return 0;
}