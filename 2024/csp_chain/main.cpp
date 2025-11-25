#include <bits/stdc++.h>
using namespace std;
//9275：[CSP-J 2024] 接龙（chain）

map<int, set<pair<int, int>>> seq_index; //start_number, row, start_pos

vector<vector<int>> sequences;

vector<vector<int>> tasks;

int T, n,  k, q;


void init_index(){
    int n = sequences.size();
    for(int row_index=0;row_index<n;row_index++){
        int seq_size = sequences[row_index].size();
 
            for(int j=0;j<=seq_size-2;j++){
                int start_number = sequences[row_index][j];
                int start_pos = j;
                // cout<<"row_index="<<row_index<<", j="<<j<<", start_number="<<start_number<<" end_number="<<end_number<<endl;
                if(seq_index.count(start_number)){
                    seq_index[start_number].insert({row_index, start_pos});
                }else{
                    seq_index[start_number] = {{row_index, start_pos}};
                }
            }
        }
    }


 

bool is_valid_task(int start_num, int round, int c, int parent_row){
    set<pair<int, int>> seqs = seq_index[start_num];
    for(auto it = seqs.begin(); it != seqs.end(); it++){
    // for(int i=0;i<seqs.size();i++){
        int row = it->first;
        int start_pos = it->second;
        //接龙不能来自同一行
        if(row == parent_row){
            continue;
        }
        int row_size = sequences[row].size();
        for(int k_current=2;k_current<=k;k_current++){
            int end_pos = start_pos + k_current - 1;
            if(end_pos < sequences[row].size()){
                int end_num = sequences[row][end_pos];
                if(end_num == c && round == 0){
                    return true;
                }

                if(round > 0){
                    bool valid = is_valid_task(end_num, round-1, c, row);
                    if(valid){
                        return true;
                    }
                }
            }else{
                break;
            }
        }
    }
    return false;
}

int main() {
    freopen("chain.in", "r", stdin);
    // freopen("chain.out", "w", stdout);

    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        seq_index.clear();
        sequences.clear();
        tasks.clear();
        for(int i=1;i<=n;i++){
            vector<int> temp;
            int seq_size;
            cin>>seq_size;
            for(int j=1;j<=seq_size;j++){
                int item;
                cin>>item;
                temp.push_back(item);
            }
            sequences.push_back(temp);
        }

        for(int i=1;i<=q;i++){
            int r, c; //round, last_item
            cin>>r>>c;
            tasks.push_back({r, c});
        }

 

        init_index();
 

        // cout<<"task size="<<tasks.size()<<endl;
        for(int i=0; i<tasks.size(); i++){
            int r = tasks[i][0];
            int c = tasks[i][1];
            // cout<<"round="<<r<<", c="<<c<<endl;
            bool valid = is_valid_task(1, r-1, c, -1);
            cout<<valid<<endl;
            
        }
    }


    return 0;
}

/**
 * 
 * g++-14 -o main.out main.cpp && ./main.out
 */