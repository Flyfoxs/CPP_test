#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges;
map<int, int> visited;
vector<int> pos;
map<int, vector<int>> adj;

vector<int> path_list;

//6695. 图中点的层次

void dijkstra(int start){
   
    priority_queue<pair<int, int> > Q;
    Q.push(make_pair( pos[start], start));
    pos[start] = 0;
    while(!Q.empty()){
        int u  = Q.top().second;
        Q.pop();
        // cout<<"u="<<u<< " visited="<<visited[u]<<endl;
        if(visited[u] == 1){
            continue;
        }
        visited[u] = 1;

        for(int v : adj[u]){
            // cout<<"u="<<u<< " v="<<v<<" visited[v]="<<visited[v]<<endl;
            if(pos[v] > pos[u] + 1){
                pos[v] = min(pos[v], pos[u] + 1);
                // cout<<"u="<<u<< " v="<<v<< " pos[v]="<<pos[v]<< " pos[u]="<<pos[u]<<endl;
                Q.push({-1* pos[v], v});
            }
        }
 
    }
}
     

int main(){
    freopen("input.in", "r", stdin);
    int n, m;
    cin>>n>>m;

    pos.resize(n+1, 99999);
    edges.resize(m);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;  
        edges[i] = make_pair(u, v);

        if(adj.count(edges[i].first)){
            adj[edges[i].first].push_back(edges[i].second);
        }else{
            adj[edges[i].first] = vector<int>{edges[i].second};
        }
    }

    
    dijkstra(1);

    if(visited[n] == 1){
        cout<<pos[n]<<endl; 
    }else{
        cout<<-1<<endl;
    }
 
    return 0;
}


/**

g++-14 -o main.out main.cpp && ./main.out
 */