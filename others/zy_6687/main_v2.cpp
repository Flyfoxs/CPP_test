#include<bits/stdc++.h>
using namespace std;
vector<int> a;
//6687. 【剪枝优化】子集和问题

vector<int> best_pos_list;
vector<int> cur_pos_list;

long long c, n;

bool is_better(vector<int> cur_pos_list){
   if(best_pos_list.size() == 0){
    return true;
   }
   int len = min(best_pos_list.size(), cur_pos_list.size());
   for(int i=0;i<len;i++){
    if(best_pos_list[i] != cur_pos_list[i]){
        return cur_pos_list[i]< best_pos_list[i] ;
    }
   }

   if(cur_pos_list.size() < best_pos_list.size()){
    return true;
   }else{
    return false;
   }
}

void print_pos_list(int score){
    if(cur_pos_list.size() == 0){
        return;
    }

    for(int i=0;i<cur_pos_list.size();i++){
        cout<<a[cur_pos_list[i]]<<" ";
    }
    cout<<" size="<<best_pos_list.size()<<", ";
    cout<<" score="<<score<<endl;
    cout<<endl;
}

int dfs(int pos, int score){
    // print_pos_list(score);
    if(best_pos_list.size() > 0){
        //已经比比现在最好的结果排序在后面了
        return 0;
    } 

    cur_pos_list.push_back(pos);
    int new_score = score + a[pos];

    if(new_score == c){
        if(is_better(cur_pos_list)){
            best_pos_list = cur_pos_list;
        }
        // return 1;
    }

    if(score < c && pos+1 < a.size()){ //小于c，继续dfs
        dfs(pos+1, new_score);
    }
    cur_pos_list.pop_back();


    if(pos+1 < a.size()){
        dfs(pos+1, score); //不选当前元素，继续dfs
    }


    return 0;
}


int main(){
    freopen("input.in", "r", stdin);
    
    cin>>n>>c;

    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // sort(a.begin(), a.end());

    int flag =  dfs(0, 0);
    if(best_pos_list.size() == 0){
        cout<<"No solution!"<<endl;
    }else{
        for(int i=0;i<best_pos_list.size();i++){
            cout<<a[best_pos_list[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**
g++-14 -o main.out main_v2.cpp && ./main.out
 */