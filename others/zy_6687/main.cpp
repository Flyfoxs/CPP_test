#include<bits/stdc++.h>
using namespace std;
vector<int> a;
//6687. 【剪枝优化】子集和问题
struct Node{
 vector<int> ans;
 vector<int> pos_list;
 long long score=0;   
};

Node best_node;

long long c, n;

bool is_better(Node node_new){
   if(best_node.score == 0){
    return true;
   }
   int len = min(best_node.pos_list.size(), node_new.pos_list.size());
   for(int i=0;i<len;i++){
    if(best_node.pos_list[i] != node_new.pos_list[i]){
        return node_new.pos_list[i]< best_node.pos_list[i] ;
    }
   }

   if(node_new.pos_list.size() < best_node.pos_list.size()){
    return true;
   }else{
    return false;
   }
}

int dfs(int pos, Node node){
    // cout<< endl <<"pos="<<pos<<" " <<endl;
    // cout<<"best_node.scre 0: ";
    // for(int i=0;i<best_node.pos_list.size();i++){
    //     cout<<a[best_node.pos_list[i]]<<" ";
    // }
    // cout<<endl;
    if(!is_better(node)){
        return 0;
    } 

    Node node_new = node;
    node_new.ans.push_back(a[pos]);
    node_new.pos_list.push_back(pos);
    node_new.score += a[pos];

    // cout<<"better  pos_list: ";
    // for(int i=0;i<node.pos_list.size();i++){
    //     cout<<a[node.pos_list[i]]<<" ";
    // }
    // cout<<endl;

    if(node_new.score == c){
        // for(int i=0;i<node_new.ans.size();i++){
        //     cout<<node_new.ans[i]<<" ";
        // }
        if(is_better(node_new)){
            best_node = node_new;
        }
        // return 1;
    }

    if(pos == a.size()-1){//dfs结束
        return 0;
    }

    if(node_new.score < c){ //小于c，继续dfs
        int flag_left = dfs(pos+1, node_new);
    }


    int flag_right = dfs(pos+1, node); //不选当前元素，继续dfs

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

    int flag =  dfs(0, Node());
    if(best_node.score == 0){
        cout<<"No solution!"<<endl;
    }else{
        for(int i=0;i<best_node.ans.size();i++){
            cout<<a[best_node.pos_list[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**
g++-14 -o main.out main.cpp && ./main.out
 */