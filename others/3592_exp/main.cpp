#include<bits/stdc++.h>
using namespace std;



 

long long cal(vector<vector<long long>> &dp, int i, int j){
    if(dp[i][j]>0){
        return dp[i][j];
    }

    long long max_val = 0;
    for(int k=i;k<j;k++){
        long long left = cal(dp, i, k);
        long long right = cal(dp, k+1, j);
        max_val = max(max_val, max(left+right, left*right));
    }
    dp[i][j] = max_val;
    // cout<<"i="<<i<<" j="<<j<<" max_val="<<max_val<<endl;
    return max_val;
}


int main(){
	freopen("input.in","r",stdin);
    int T, n;
   
    cin>>T;
    while(T--){
        cin>>n;
        // cout<<"n="<<n<<endl;
        vector<vector<long long>> dp (n, vector<long long>(n, 0));
        // cout<<"n="<<n<<endl;
    

        for(int i=0;i<n;i++){
            int temp; 
            cin>>temp;
            // cout<<"temp="<<temp<<endl;
            dp[i][i] = temp;
        }


        for(int i=0;i<n;i++){
            // cout<<dp[i][i]<<" ";
        }
        cout<<cal( dp, 0, n-1)<<endl  ;
    }
    return 0;
}
