#include <bits/stdc++.h>
using namespace std;
// 7172：【AHOI2024初中】计数 (d)(4)
// https://ask.csdn.net/questions/8107935 
 
const int N=3005,mod=1e9+7;
int n,m,f1[N][N],f0[N][N]; // f1记录能吃完的情况，f0记录不能吃完的情况

int main(){
    freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
    cin>>n>>m;
    f1[0][0]=1; // 初始状态，没有糖果时，视为一种可以吃完的状态

    // 遍历每个位置i
    for(int i=0;i<n;i++)
    {
        // 对于位置i，考虑之前的所有j种颜色
        for(int j=0;j<=i;j++)
        {
            // f1[i+1][j]的转移：如果前i个位置存在j种颜色且能吃完，
            // 则i+1位置保持这j种颜色不变能吃完的方法数增加j种（因为新颜色可以与之前的任意一种颜色相同）
            f1[i+1][j]=(f1[i+1][j]+1ll*f1[i][j]*j)%mod;

            // 同理，如果前i个位置存在j种颜色但不能吃完，
            // 则通过新增一个与之前某相同颜色的糖果配对成功，变为能吃完
            f1[i+1][j]=(f1[i+1][j]+1ll*f0[i][j]*j)%mod;

            // 更新f0[i+1][j+1]：如果前i个位置存在j种颜色且不能吃完，
            // 则在i+1位置新增一种颜色（与之前j种不同），依然不能吃完，方法数增加m-j种
            f0[i+1][j+1]=(f0[i+1][j+1]+1ll*f1[i][j]*(m-j))%mod;

            // 如果前i个位置存在j种颜色且能吃完，
            // 在i+1位置新增一种颜色（与之前j种不同）会使得当前不能吃完
            f0[i+1][j]=(f0[i+1][j]+1ll*f0[i][j]*(m-j))%mod;
        }
    }

    // 统计最终能吃完的序列数量，即所有dpi,n,1的和
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=f1[n][i];
        ans%=mod;
    }

    cout<<ans; // 输出答案
    return 0;
}


/**
 g++-14 -o main.out main.cpp && ./main.out

  
 */