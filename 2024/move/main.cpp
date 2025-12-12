#include <bits/stdc++.h>
using namespace std;
#define ll long long;
// 9438. 【2024年庐阳区初中区赛】充电桩（move）(4) 

vector<long long> a;
int main() {
    freopen("move.in", "r", stdin);
    // freopen("move.out", "w", stdout);
    
    int n;
    cin >> n;
    a.resize(n, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
     
    long long ans = 0;
    for(int i=0;i<n;i++){
        a[i] = a[i] - i;
    }

    // long long min_ans = 999999999999999999;
    int mid_index = n/2;
    cout<<"mid_index="<<mid_index<<endl;

    long long t =a[mid_index];


    long long cur_ans = 0;
    //并不少所有的右边都比t大，所以需要判断
    for(int j=0; j<n; j++){
        cur_ans += abs(a[j] - t);
    }
    // min_ans = min(min_ans, cur_ans);
    // cout<<"cur_ans="<<cur_ans<<endl;
  
    cout<<cur_ans<<endl;
    return 0;

     
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */