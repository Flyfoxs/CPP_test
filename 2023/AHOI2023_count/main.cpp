# include<bits/stdc++.h>
using namespace std;

vector<int> a;

int dfs(int index, vector<int> cur){
    // cout<<"index="<<index<<", cur: ";
    // for(int i=0;i<cur.size();i++){
    //     cout<<cur[i]<<" ";
    // }
    // cout<<endl;
    if(cur.size() == 3){

        if(cur[0] + cur[1] > cur[2] && cur[0] + cur[2] > cur[1] && cur[1] + cur[2] > cur[0]){
            return 1;
        }
        return 0;
    }

    if(index == a.size()){
        // cout<<"end, index="<<index<<", cur: ";
        return 0;
    }

    if(cur.size()==2){
        if(cur[0] + cur[1] <= a[index]){
            // cout<<"end, index="<<index<<", cur: " << endl;;
            return 0;
        }
    }
    vector<int> cur_copy = cur;
    cur_copy.push_back(a[index]);

    return dfs(index+1, cur) + dfs( index+1, cur_copy);
}

int main(){
    freopen("count.in", "r", stdin);
    // freopen("count.out", "w", stdout);
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    int ans = dfs(0, vector<int>());
    cout<<ans<<endl;
    return 0;
}