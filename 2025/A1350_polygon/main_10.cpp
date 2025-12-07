#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
bool is_polygon(vector<long long> &a){
    long long sum = 0;

    if(a.size()<3){
        return false;
    }
    for(int i=0;i<a.size();i++){
        sum += a[i];
    }
    if (sum>2*a[0]){
        return true;
    }
    return false;
}

int dfs(vector<long long> &a, vector<long long> &cur, int index){

    if(index == a.size()){
        // cout<<"end, index="<<index<<" cur size="<<cur.size()<<endl;
        // for(int i=0;i<cur.size();i++){
        //     cout<<cur[i]<<" ";
        // }
        // cout<<endl;
        return 0;
    }

 
    //Without index
    dfs(a, cur, index+1);
    // cout<<"Without index:"<<index<<". "<<endl;
    // for(int i=0;i<cur.size();i++){
    //     cout<<cur[i]<<" ";
    // }
    // cout<<endl;
    //With index
    vector<long long> cur_copy = cur;
    cur_copy.push_back(a[index]);
    if(is_polygon(cur_copy)){
        ans++;
    }
    dfs(a, cur_copy, index+1);
    // cout<<"With    index:"<<index<< ". ";
    // for(int i=0;i<cur_copy.size();i++){
    //     cout<<cur_copy[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}

int main()
{
    // polygon
    freopen("input_10.in", "r", stdin);
    // freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    // cout<<"n="<<n<<endl;
    vector<long long> a(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> cur;
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    dfs(a, cur, 0);
    cout<<ans<<endl;
 
    return 0;
}



/**
 g++-14 -o main.out main_10.cpp && ./main.out
 */