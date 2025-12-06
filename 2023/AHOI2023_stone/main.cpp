#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long ans = 0;
int N;
long long inf = 999999999999999999;

map<pair<int, int>, long long> dp;

long long sum(int left, int right){
    long long sum = 0;
    for(int i=left;i<=right;i++){
        sum += a[i];
    }
    return sum;
}

// score change from [left, right] to [1->N]
long long dfs(int left, int right){
    if(left==1 && right==N){
        return 0;
    }
    if(dp.count({left, right})){
        return dp[{left, right}];
    }
    long long left_score = inf;
    long long right_score = inf;
    if(left>1){
        left_score = dfs(max(left-1, 1), right) + sum(left, right) + a[left-1];
    } 
    if(right<N){
        right_score = dfs(left, min(right+1, N)) + sum(left, right) + a[right+1];
    } 
    // cout<<"left="<<left<<" right="<<right<<" left_score="<<left_score<<" right_score="<<right_score<<endl;
    // cout<<"min(left_score, right_score)="<<min(left_score, right_score)<<endl;


    dp[{left, right}] = min(left_score, right_score);
    return min(left_score, right_score);
}
int main(){
    freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    long long n, l, r;
    cin>>n>>l>>r;
    N = n;
    a.resize(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
 
    for(int i=l;i<=r;i++){
        // cout<<"left="<<i<<" right="<<i<<endl;
        ans = dfs(i,i);
        cout<< ans << " ";
    }
    // cout<<ans<< endl;
    return 0;
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */