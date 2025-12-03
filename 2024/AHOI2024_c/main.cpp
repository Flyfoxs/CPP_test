#include <bits/stdc++.h>
using namespace std;
// 7171：【AHOI2024初中】操作 (c)(3)

vector<int> mat_n ; //操作结果矩阵
vector<vector<int>> mat_m; // 机器矩阵
vector<int> oper_c; // 操作矩阵
map<int, int> oper_c_map; // effect_map[i]表示机器i执行一次对位置j的增量
vector<vector<int>> effect; // effect[i][j]表示机器i执行一次对位置j的增量


// 预处理：计算每个机器执行一次的效果
void precompute_effect(int n, int m){
    effect.resize(m+1, vector<int>(n+1, 0));
    // 从1到m依次计算，因为机器i只能调用编号小于i的机器
    for(int i=1; i<=m; i++){
        int kind = mat_m[i][0];
        int a = mat_m[i][1];
        int y = mat_m[i][2];
        
        if(kind == 1){
            effect[i][a] = (effect[i][a] + y) % 10007;
        }else if(kind == 2){
            int left = min(a, i-1);
            int right = min(y, i-1);
            // 叠加范围内所有机器的效果
            for(int j=left; j<=right; j++){
                for(int pos=1; pos<=n; pos++){
                    effect[i][pos] = (effect[i][pos] + effect[j][pos]) % 10007;
                }
            }
        }
    }
}

// 执行机器（优化版本：直接应用预处理的效果）
void exec_machine_optimized(int machine_index){
    int count = oper_c_map[machine_index];
    for(int i=1; i<mat_n.size(); i++){
        mat_n[i] = (mat_n[i] + effect[machine_index][i]*count) % 10007;
    }
}

void exec_machine(int machine_index){
    // cout<<"machine_index="<<machine_index<<endl;
    int kind = mat_m[machine_index][0];
    int a = mat_m[machine_index][1];
    int y = mat_m[machine_index][2];
    
    if(kind == 1){
        mat_n[a] = (mat_n[a]+ y) % 10007;
    }else if(kind == 2){
        // cout<<"exec_machine i="<<machine_index<<" left="<<min(a, machine_index-1)<<" right="<<min(y, machine_index-1)<<endl;

        for(int i=min(a, machine_index-1);i<=min(y, machine_index-1);i++){
            exec_machine(i);
        }
    }
}

void print_n(){
    cout<<"print_n: ";
    for(int i=1;i<mat_n.size();i++){
        cout<<mat_n[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);

    int n, m, k;
    cin>>n>>m>>k;
    // cout<<"n="<<n<<" m="<<m<<" k="<<k<<endl;

    mat_n.resize(n+1);
    mat_n.assign(n+1, 0);

    oper_c.resize(k+1);
    for(int i=1;i<k+1;i++){
        int cur_oper;
        cin>>cur_oper;
        oper_c[i] = cur_oper;
        if(oper_c_map.count(cur_oper) == 0){
            oper_c_map[cur_oper] = 1;
        }else{
            oper_c_map[cur_oper]++;
        }

    }

    mat_m.resize(m+1, vector<int>(3));
    for(int i=1;i<m+1;i++){
        cin>>mat_m[i][0]>>mat_m[i][1]>>mat_m[i][2];
    }

    // 预处理每个机器的效果
    precompute_effect(n, m);

    //执行操作（使用优化版本）
    // for(int i=1;i<k+1;i++){
    //     int machine_index = oper_c[i];
    //     exec_machine_optimized(machine_index);
    //     // print_n();
    // }

    for(auto it = oper_c_map.begin(); it != oper_c_map.end(); it++){
        // cout<<it->first<<" "<<it->second<<endl;
        int machine_index = it->first;
        exec_machine_optimized(machine_index);
    }


    for(int i=1;i<n+1;i++){
        // cout << "i="<<i<<", ";
        cout<<mat_n[i]<<" ";
    }
    return 0;
}



/**
 * 
  g++-14 -o main.out main.cpp && ./main.out
 */