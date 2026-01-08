#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
long long dp[1009] = {-99999};

int n, m;


int main(){
    freopen("grid.in","r",stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    } 

    dp[0] = a[0][0];
    for(int i=1;i<n;i++){
       dp[i] = dp[i-1] + a[i][0];
    }

    // i:n 行, j:m 列
    for(int j=1;j<m;j++){
        vector<long long> up(n, -99999);
        vector<long long> down(n, -99999);
        // long long up[n] = {-99999};
        // long long down[n] = {-99999};
        //left -> right
        for(int i=0;i<n;i++){
            up[i] =  dp[i] + a[i][j];
            down[i] = dp[i] + a[i][j];
        }

        for(int i=n-2;i>=0;i--){
            up[i] = max(up[i], up[i+1] + a[i][j]);
        }

        for(int i=1;i<n;i++){
            down[i] = max(down[i], down[i-1] + a[i][j]);
        }

        for(int i=0;i<n;i++){
            dp[i] = max(up[i], down[i]);
        }
         
   
        
    }
    // End

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<"--------"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n-1]<<endl;

   return 0;

}

/**
g++-14 -o main.out main.cpp && ./main.out
*/