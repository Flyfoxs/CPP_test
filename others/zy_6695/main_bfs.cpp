#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist, parent;

int main(){
    freopen("input.in", "r", stdin);
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    dist.assign(n+1, -1);
    parent.assign(n+1, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(dist[n] == -1){
        cout << -1 << endl;
        return 0;
    }

    cout << dist[n] << endl;

    // 打印最短路径
    vector<int> path;
    for(int cur = n; cur != -1; cur = parent[cur]){
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    for(int x : path){
        cout << x << " ";
    }
    cout << endl;
    // 打印最短路径结束

    return 0;
}

/**
 * g++-14 -o main.out main_dfs.cpp && ./main.out
 */