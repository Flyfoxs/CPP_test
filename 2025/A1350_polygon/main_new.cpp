#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int n;
vector<long long> a; 
bool is_polygon(vector<int> &a){
    long long sum = 0;

    if(a.size()<3){
        return false;
    }
    for(int i=0;i<a.size();i++){
        sum += a[i];
    }
    if (sum>2*a[a.size()-1]){
        return true;
    }
    return false;
}

int resolve(){
    int ans=0;
    for(long long i=0; i < (1<<n); i++){
        vector<int> a_list ;
        for(long long j=0; j<=n; j++){
            if(i & (1<<j) ){
                a_list.push_back(a[j]);
                // cout<<a[j]<< " ";
            }
        }
        // cout<<", i="<<i<<endl;
        if(a_list.size()>=3){
            if(is_polygon(a_list)){
                // cout<<"i="<<i<<endl;
                ans++;
            }
        }

    }
    return ans;
}

int main()
{
    // polygon
    freopen("polygon.in", "r", stdin);
    // freopen("input_10.in", "r", stdin);
    // freopen("polygon.out","w",stdout);

    cin >> n;
    // cout<<"n="<<n<<endl;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    ans = resolve();
    cout<<ans<<endl;
 
    return 0;
}



/**
 g++-14 -o main.out main_new.cpp && ./main.out
 */