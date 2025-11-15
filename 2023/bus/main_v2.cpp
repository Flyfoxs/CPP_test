#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (1LL<<60);

int main() {
    freopen("0_in.txt", "r", stdin); //74806409
    cin.tie(nullptr);
    
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    struct Edge { int to; int a; };
    vector<vector<Edge>> g(n+1);
    int u,v; int a;
    int max_a = 0;
    for (int i=0;i<m;i++){
        cin >> u >> v >> a;
        g[u].push_back({v, a});
        max_a = max(max_a, a);
    }
    // Upper bound for enumerating start times T = q*k:
    // If we start later than max_a + n, it's unlikely to improve earliest departure.
    // (heuristic safe upper bound)
    ll maxT = (ll)max_a + n + 5; // margin
    
    // We'll enumerate q so that T = q*k and T <= maxT
    ll answer = -1;
    // To avoid too many iterations if k is small and maxT large, we also cap number of T iterations
    ll maxIterations = (maxT / max(1, k)) + 5;
    
    pair(1,2);
    tuple(1,2,3);
   
    for (ll q = 0; q <= maxIterations; ++q) {
        ll T = q * 1LL * k;
        if (T > maxT) break;
        // BFS from node 1; state is (node, depth)
        // We don't want repeated visits with same node and same depth%k (because future constraints depend on absolute depth)
        vector<array<int, 101>> visited; // we only use first k entries per node; but allocate dynamically
        // since k <= 100 per statement, we can store fixed-size array for speed
        visited.resize(n+1);
        for (int i=1;i<=n;i++){
            for (int r=0;r<k;r++) visited[i][r]= -1;
        }
        deque<pair<int,int>> dq;
        // start at node 1 with depth 0 (arrived at entrance at time T)
        visited[1][0] = 0;
        dq.emplace_back(1, 0);
        bool found = false;
        while (!dq.empty() && !found) {
            auto [cur, depth] = dq.front(); dq.pop_front();
            ll curTime = T + depth; // absolute time when at node cur before taking next edge
            // traverse all outgoing edges
            for (auto &e : g[cur]) {
                if (e.a > curTime) continue; // cannot traverse this edge at this absolute time
                int nxt = e.to;
                int nd = depth + 1;
                int r = nd % k;
                if (visited[nxt][r] != -1) continue;
                visited[nxt][r] = nd;
                // check if we've reached exit with length multiple of k
                if (nxt == n && (nd % k == 0)) {
                    ll departTime = T + nd;
                    if (answer == -1 || departTime < answer) answer = departTime;
                    found = true;
                    break;
                }
                // push forward
                dq.emplace_back(nxt, nd);

        }
        if (found) break; // since T enumerated from small to large, first found is minimal departure
    }
    
    if (answer == -1) cout << -1 << "\n";
    else cout << answer << "\n";
    return 0;
}
