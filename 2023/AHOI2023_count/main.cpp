# include<bits/stdc++.h>
using namespace std;
// 6247：[AHOI2023初中组]数数 (count)
vector<long long> a;

int dfs(int index, vector<long long> cur){
    if(cur.size() == 3){

        if(cur[0] + cur[1] > cur[2] ){
            return 1;
        }
        return 0;
    }

    if(index == a.size()){
        // cout<<"end, index="<<index<<", cur: ";
        return 0;
    }

    if(cur.size()==2){
        long long ans_cur = 0;
        for(int i=index; i<a.size();i++){
            if(cur[0] + cur[1] <= a[i]){
                break;
            }
            ans_cur ++;
        }
        return ans_cur;
    }
    vector<long long> cur_copy = cur;
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
    int ans = dfs(0, vector<long long>());
    cout<<ans<<endl;
    return 0;
}