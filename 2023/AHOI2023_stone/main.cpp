#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long ans = 0;
int N;
long long inf = 999999999999999999;
vector<long long> sum_arr;
long long n, l, r;

map<pair<int, int>, long long> dp;

// long long dp[5000][5000] = {0};

long long sum(int left, int right){
    return sum_arr[right] - sum_arr[left-1];
}

// score change from [left, right] to [1->N]
long long dfs(int left, int right){
    if(left==1 && right==N){
        return 0;
    }
    if(dp.count(make_pair(left, right))){

        return dp[make_pair(left, right)];
    }
    long long left_score = inf;
    long long right_score = inf;
    long long S = sum(left, right);
    // cout<<"S="<<S<<" left="<<left<<" right="<<right<<endl;
    if(left>1){
        left_score = dfs(left-1, right) + S + a[left-1];
    } 
    if(right<N){
        right_score = dfs(left, right+1) + S + a[right+1];
    } 
    // cout<<"left="<<left<<" right="<<right<<" left_score="<<left_score<<" right_score="<<right_score<<endl;
    // cout<<"min(left_score, right_score)="<<min(left_score, right_score)<<endl;
   
    dp[make_pair(left, right)] = min(left_score, right_score);
    // cout<<"left="<<left<<" right="<<right<<" min(left_score, right_score)="<<min(left_score, right_score)<<endl;

    return min(left_score, right_score);
}
int main(){
    freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    cin>>n>>l>>r;
    N = n;
    a.resize(n+1,0);
    sum_arr.resize(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum_arr[i] = sum_arr[i-1] + a[i];
    }
 
    for(int i=l;i<=r;i++){
        ans = dfs(i,i);
        cout<< ans << " ";
    }
    // cout<<ans<< endl;
    return 0;
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */