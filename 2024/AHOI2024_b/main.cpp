#include <bits/stdc++.h>
using namespace std;
//7170. 【AHOI2024初中】立方根 (b)(2) 

map<pair<long long, long long>, long long> mat_n ; //操作结果矩阵

long long max_root = 1ll;
 

void init_mat(long long sqre){
    long long cur_ans = 0;
    for(long long i=max(1ll, max_root);i<= ceil(cbrt(sqre)) + 1;i++){
        long long index_begin = pow( i, 3);
        long long index_end = pow( i+1, 3)-1;
        mat_n[{index_begin, index_end}] = i;
        max_root = i; 
    }
    for(auto it = mat_n.begin(); it != mat_n.end(); it++){
        // cout<<"index_begin="<<it->first.first<<" index_end="<<it->first.second<<" square_root="<<it->second<<" sqre="<<sqre << " max_root="<<max_root<<endl;
        
    }
}


long long sum_mat(long long sqre){
    init_mat(sqre);
    long long previes_index = 0;
    long long previes_square_root = 0;
    long long sum = 0;
    for(auto it = mat_n.begin(); it != mat_n.end(); it++){
        long long cur_index_begin = it->first.first;
        long long cur_index_end = it->first.second;
        long long cur_square_root = it->second;

        cur_index_end = min(cur_index_end, sqre);
        sum = sum + (cur_index_end - cur_index_begin +1) * cur_square_root;
         

        // cout<<"cur_index_begin="<<cur_index_begin<<" cur_index_end="<<cur_index_end <<" cur_square_root="<<cur_square_root<<" sqre="<<sqre<<" sum="<<sum<<endl;
 

        if(cur_index_end >= sqre){
            break;
        }
    }
    // cout<<"sqre="<<sqre<<" sum="<<sum<<endl;
    return sum;
}



int main()
{
    freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);

    long long q, n;
    cin>>q;
    while(q--)
    {
        cin>>n;
        cout<<sum_mat(n)<<endl;
        
    }
    return 0;
}



/**
 * 
  g++-14 -o main.out main.cpp && ./main.out
 */