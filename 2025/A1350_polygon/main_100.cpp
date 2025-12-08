#include<bits/stdc++.h>
using namespace std;

// a[i] 已排序
// f[i][s]  : 前缀 1..i 子集和 = s 的方案数 (s=5001 表示 >5000)
// f2[i][s] : 后缀 i..n 子集和 <= s 的方案数（构造时先做精确，再前缀和）
int n, a[5005], mod = 998244353;
int f[5005][5005], f2[5005][5005];
int dl = 0, de = 0, op = 0, kl = 0;

int main(){
    freopen("polygon.in","r",stdin);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);

    // 前缀子集和 DP（精确）
    f[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=5001;j>=0;j--){
            f[i+1][j] = f[i][j];
            if(j + a[i+1] <= 5000)
                f[i+1][j + a[i+1]] = (f[i+1][j + a[i+1]] + f[i][j]) % mod;
            else
                f[i+1][5001] = (f[i+1][5001] + f[i][j]) % mod;
        }
    }

    // 后缀子集和 DP（精确）
    f2[n+1][0] = 1;
    for(int i=n+1;i>=2;i--){
        for(int j=5001;j>=0;j--){
            f2[i-1][j] = f2[i][j];
            if(j + a[i-1] <= 5000)
                f2[i-1][j + a[i-1]] = (f2[i-1][j + a[i-1]] + f2[i][j]) % mod;
            else
                f2[i-1][5001] = (f2[i-1][5001] + f2[i][j]) % mod;
        }
    }

    // 后缀 DP 转成 “和 ≤ j 的方案数”
    for(int i=n+1;i>=1;i--)
        for(int j=1;j<=5001;j++)
            f2[i][j] = (f2[i][j] + f2[i][j-1]) % mod;

    // dl = 统计所有 (i,j) 满足 a[i] >= a[j] 的有序对
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i] >= a[j]) dl++;
    
    // op = 卷积统计：左和 + 右和 <= a[i]
    for(int i=1;i<=n;i++)
        for(int j=0;j<=a[i];j++)
            op = (op + 1LL * f[i-1][j] * f2[i+1][a[i]-j]) % mod;

    // de = 2^n - n - C(n,2) - 1
    de = 1;
    for(int i=1;i<=n;i++) de = (de * 2) % mod;
    de = (de - 1 - n - 1LL*n*(n-1)/2) % mod;
    de = (de + mod) % mod;

    // 最终答案
    kl = (de + dl - op + mod) % mod;
    cout << kl << endl;
    return 0;
}
