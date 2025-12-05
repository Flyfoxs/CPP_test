#include<bits/stdc++.h>
using namespace std;

//6246. [AHOI2023初中组]评分 (score)
int main(){
    freopen("score.in", "r", stdin);
    // freopen("score.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<pair<long long, int>> score_map;
    vector<vector<long long>> score(n, vector<long long>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>score[i][j];
        }
        sort(score[i].begin(), score[i].end());
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<score[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++){
        long long sum = 0;
        for(int j=1;j<m-1;j++){
                sum += score[i][j];
        }
        // cout<<"sum="<<sum<<" i="<<i<<endl;
        score_map.push_back(make_pair(sum, i));
    }
    sort(score_map.begin(), score_map.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first){
            return a.second < b.second;
        }else{
        return a.first > b.first;
        }
    });

    for(int i=0;i<n;i++){
        cout<<score_map[i].second+1<<" ";
    }
    cout<<endl;
    return 0;
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */