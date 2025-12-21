#include <bits/stdc++.h>
using namespace std;
//7170. 【AHOI2024初中】立方根 (b)(2) 

map<pair<long long, long long>, long long> mat_n ; //操作结果矩阵

long long max_root = 1ll;

 
long long pow_long(long long base){
    return base*base*base;
}


long long sum_range(long long begin, long long end){
    long long root = floor(cbrt(begin));
    long long root_end = ceil(cbrt(end));
    // cout<<"root="<<root<<" root_end="<<root_end<<endl;
    long long sum = 0;
    for(long long i=root;i<=root_end ;i++){
        long long cur_root = i;

        long long cur_begin = max(begin, pow_long(i));
        long long cur_end = min(end, pow_long(i+1)-1);

        sum = sum + cur_root* max(0ll, cur_end - cur_begin + 1);
        // cout<<"i="<<i<<" cur_begin="<<cur_begin<<" cur_end="<<cur_end<<" cur_root="<<cur_root<<" sum="<<sum<<", end="<<end<<endl;  

    }
    return sum;
}

int main()
{

    // cout<<sum_range(2, 8)<<endl;
    freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);

    long long q, x;
    cin>>q;

    long long previous_x = 0;
    long long sum = 0;
    while(q--)
    {
        long long x = 0;
        cin>>x;
        sum = sum + sum_range(previous_x+1, x);

        cout<<sum<<endl;
        previous_x = x;
    }
    return 0;
}



/**
 * 
  g++-14 -o main.out main.cpp && ./main.out
 */