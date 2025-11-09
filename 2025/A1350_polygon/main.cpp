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


long long jc(int n){
    if(n==0){
        return 0;
    }
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans * i;
        ans = ans % 998,244,353;
    }
    cout<<"jc("<<n<<")="<<ans<<endl;
    return ans;
}



int dfs(vector<long long> &a, vector<long long> &cur, int index, bool polygon_flag){
    if(index == a.size()){
        // cout<<"end, index="<<index<<" cur size="<<cur.size()<<endl;
        // for(int i=0;i<cur.size();i++){
        //     cout<<cur[i]<<" ";
        // }
        // cout<<endl;
        return 0;
    }

 
    //Without index
    dfs(a, cur, index+1, polygon_flag);
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
        polygon_flag = true;
        // ans = ans % 998,244,353;
        int remaining_index = a.size()-index-1;
        cout<<"index="<<index<<", remaining_index="<<remaining_index<<" a.size()="<<a.size()<<", ";
        for(int i=0;i<cur_copy.size();i++){
            cout<<cur_copy[i]<<" ";
        }
        cout<<endl;
        ans = ans + pow(2, remaining_index)-1;
        return 0;
    }
    dfs(a, cur_copy, index+1, polygon_flag);
    // cout<<"With    index:"<<index<< ". "<<"flag:"<<polygon_flag<<endl;
    // for(int i=0;i<cur_copy.size();i++){
    //     cout<<cur_copy[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}




int main()
{
    // polygon
    freopen("input_big.in", "r", stdin); //74806409
    // freopen("output.out","w",stdout);
    int n;
    cin >> n;
    // cout<<"n="<<n<<endl;
    vector<long long> a(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] < a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }

    vector<long long> cur;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    dfs(a, cur, 0, false);
    cout<<ans<<endl;
 
    return 0;
}



/**
 g++-14 -o main.out main.cpp && ./main.out

 74806409
 */