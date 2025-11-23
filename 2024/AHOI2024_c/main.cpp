#include <bits/stdc++.h>
using namespace std;
// 7171：【AHOI2024初中】操作 (c)(3)

vector<int> mat_n ; //操作结果矩阵
vector<vector<int>> mat_m; // 机器矩阵
vector<int> oper_c; // 操作矩阵

//执行li到ri的机器
void exec(int i, int j){
    for(int k=i;k<=j;k++){
        int a = mat_m[k][1];
        int y = mat_m[k][2];
        mat_n[a] = mat_n[a] + y;
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
        cin>>oper_c[i];

    }

    mat_m.resize(m+1, vector<int>(3));
    for(int i=1;i<m+1;i++){
        cin>>mat_m[i][0]>>mat_m[i][1]>>mat_m[i][2];
    }

    // cout<<"mat_m:"<<endl;
    // for(int i=1;i<m+1;i++){
    //     // cout<<mat_m[i][0]<<" "<<mat_m[i][1]<<" "<<mat_m[i][2]<<endl;
    // }

    //执行操作
    for(int i=1;i<k+1;i++){
        int machine_index = oper_c[i];
        exec_machine(machine_index);
        // print_n();
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