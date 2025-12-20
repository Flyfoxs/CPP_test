#include <bits/stdc++.h>
using namespace std;
/**
递归求解
*/
vector<long long> a;
vector<long long> b; //前缀和
map<pair<int, int>, long long> dp;
int cal(int left, int right)
{
    if(left == right){
        return 0;
    }
    if(left + 1 == right){
        return b[right] - b[left-1];
    }
    if (dp.count(make_pair(left, right)))
    {
        return dp[make_pair(left, right)];
    }else{
        dp[make_pair(left, right)] = 999999999999999999;
        for(int i=left; i<right; i++){
            long long left_score = cal(left, i);
            long long right_score = cal(i+1, right);
            long long score = left_score + right_score + b[right] - b[left-1];
            // cout << "left=" << left << " right=" << right << " i=" << i << " left_score=" << left_score << " right_score=" << right_score << " score=" << score << endl;
            dp[make_pair(left, right)] = min(dp[make_pair(left, right)], score);
        }
        return dp[make_pair(left, right)];
    }
}

int main()
{
    // freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    a.resize(n+1);
    b.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << cal(1, n) << endl;
    return 0;
}

/**
g++-14 -o main.out main_ex.cpp && ./main.out
 * 
 */