#include <bits/stdc++.h>
using namespace std;

int cal(vector<long long> &input, long long target){
    int size = input.size();
    // for(int i=0;i<input.size();i++){
    //     cout<<input[i]<<" ";
    // }
    // cout<<endl;
    
    vector<long long> prefix_sum(input.size());
    prefix_sum[0] = input[0];
    for(int i=1;i<input.size();i++){
       prefix_sum[i] = prefix_sum[i-1] ^ input[i];
    }

    // for(int i=0;i<input.size();i++){
    //     cout<<prefix_sum[i]<<" ";
    // }
    // cout<<endl;

    long long ans = 0;

    for(int i=0; i<size; i++){
        long long sum_begin = 0;
        if(i>0) {
            sum_begin = prefix_sum[i-1];
        }
        for(int j=i;j<size;j++){
            long long range_sum = prefix_sum[j] ^ sum_begin;

            cout<<"xxx i="<<i<<" j="<<j<<" prefix_sum[j]="<<prefix_sum[j]<<" sum_begin="<<sum_begin<<" range_sum="<<range_sum<<endl;
            if(range_sum == target){
                // cout<<"i="<<i<<" j="<<j<<" range_sum="<<range_sum<<" target="<<target<<endl;
                i=j;
                // cout<<"i=j="<<j<<endl;
                ans++;
                break;
            }
        }
    }


    cout<<ans;
    return ans;
}

 
int main()
{
    // xor
    freopen("input.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    int n;
    cin >> n;

    long long target;
    cin>>target;
    vector<long long> a(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cal(a, target);
    cout<<endl;
    return 0;
}



/**
 g++-14 -o main.out main.cpp && ./main.out
 */