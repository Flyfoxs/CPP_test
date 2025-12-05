#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int ans = 0;

int dfs(int left, int right, int begin){
    // cout<<"left="<<left<<" right="<<right<<" begin="<<begin<<endl;
    if(left<0 && right > a.size()-1){
        return 0;
    }

    if( a[left] > a[right] && right <= a.size()-1
    || left < 0){
        begin = begin + a[right];
        // cout<<"right, left="<<left<<" right="<<right<<" begin="<<begin<<" ans="<<ans<<endl;
        ans = begin + dfs(left, right+1, begin);
        // cout<<"> right, ans="<<ans<<", left="<<left<<" right="<<right<<" begin="<<begin<<endl;
    }else{
        begin = begin + a[left];
        // cout<<"left, left="<<left<<" right="<<right<<" begin="<<begin<<" ans="<<ans<<endl;
        ans = begin + dfs(left-1, right, begin);
        // cout<<"> left, ans="<<ans<<", left="<<left<<" right="<<right<<" begin="<<begin<<endl;
    }
    return ans;
}
int main(){
    freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    int n, l, r;
    cin>>n>>l>>r;
    l = l-1;
    r = r-1;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
 
    for(int i=l;i<=r;i++){
        ans =  dfs(i-1, i+1, a[i]);
        cout<< ans << " ";
    }
    return 0;
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */