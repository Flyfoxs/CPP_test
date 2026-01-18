#include<bits/stdc++.h>
using namespace std;
vector<int> a;
struct Node{
 vector<int> ans;
 long long score;   
};

long long c, n;

int dfs(int pos, Node node){
    Node node_new = node;
    node_new.ans.push_back(a[pos]);
    node_new.score += a[pos];

    if(node_new.score == c){
        for(int i=0;i<node_new.ans.size();i++){
            cout<<node_new.ans[i]<<" ";
        }
        return 1;
    }

    if(node_new.score > c){
        return 0;
    }

    if(pos == a.size()-1){
        return 0;
    }

    int flag_left = dfs(pos+1, node_new);
    if(flag_left == 1){
        return 1;
    }
    int flag_right = dfs(pos+1, node);
    if(flag_right == 1){
        return 1;
    }
    return 0;
}

int main(){
    // freopen("input.in", "r", stdin);
    
    cin>>n>>c;

    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // sort(a.begin(), a.end());

    int flag =  dfs(0, Node());
    if(flag == 0){
        cout<<"No solution!"<<endl;
    }
    return 0;
}

/**
g++-14 -o main.out main.cpp && ./main.out
 */