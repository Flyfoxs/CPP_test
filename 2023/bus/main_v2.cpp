// 爱码岛编程 P9751 
// 6544：[CSP-J 2023] 旅游巴士（bus）
#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int MAXN = 1e4 + 10;

/**
 * 一条边 edge 表示：
 *   u -> v (由于我们存在 g[u] 中，所以起点 u 隐含)
 *   a = 这条路第一班车可以出发的最早时间
 * 
 * 注意：之后每隔 k 分钟发一班车，因此如果你在时间 t < a 到达，
 *       需要等待直到时间 a、a+k、a+2k ... 的最近的一个。
 */
struct edge {
    int v; // 边的终点 u -> v
    int a; // 该边的最早出发时间限制 a
    edge(int v, int a) : v(v), a(a) {}
};

// 图：邻接表 g[u] 中存放所有从 u 出发的边
vector<edge> g[MAXN];

/**
 * f[u][j] = 到达城市 u、且当前时间 t mod k == j 的最短时间
 *
 * 为什么需要取模？
 *   因为公交车周期是 k，这意味着等待情况取决于 t % k。
 *   对同一个 t % k 状态，如果已经访问过，再遇到就没必要重复计算。
 */
int f[MAXN][105];

// visited[u][j]: 是否已经处理（确定最短）节点 (u, t % k == j)
int visited[MAXN][105];

int n, m, k;

/**
 * Dijkstra 最短路（考虑等待时间 + 时间周期）
 */
void djikstra() {

    /**
     * 优先队列 pq 存 pair< -时间 , 城市 >。
     * 为什么存负时间？
     *   因为 C++ 的 priority_queue 默认是大根堆，
     *   我们需要“最小时间优先”，所以存负值，负的越大（越接近 0）表示时间越小。
     *   这样 top() 永远给我们当前“最短时间”的点。
     */
    priority_queue<PII> q;

    // 初始状态：在 时间 0, 城市 1
    q.push(make_pair(0, 1)); 


    while (!q.empty()) {

        // 取出当前时间最小的点
        int t = abs(q.top().first); // 因为我们存的是 -time
        int u = q.top().second; // 当前城市
        q.pop();
        cout << "====== t=" << t << ", u=" << u << " g[*] size=" << g[u].size() << " q size=" << q.size() << " =======" << endl;

        // 当前时间的 (mod k)
        int j = t % k;

        // 如果状态 (u, j) 已经确定过，就跳过, 特别是一个节点如果有多个入边的时候, 结果没有影响, 但是会影响性能
        if (visited[u][j]) {
            cout << "visited[u][j] = 1," << u << ", " << j << " continue" << endl;
            continue;
        }
        visited[u][j] = 1;  // 标记为已确定

        // 遍历所有从 u 出发的边
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].v; // 下一站
            int a = g[u][i].a; // 最早出发时间限制
            // cout << "next v=" << v << ", a=" << a << endl;

            /**
             * 当前到达时间为 t。
             * 判断是否可以立即走：
             *   如果 t >= a，则可以直接出发。
             *   否则 t < a，需要等待到下一班车。
             */
            if (t >= a) {
                // 直接出发，不需要等待，花费时间 +1（题目中每条边花费 1 分钟）

                if (f[u][j] + 1 < f[v][(j + 1) % k]) {
                    f[v][(j + 1) % k] = f[u][j] + 1;

                    // 推入队列，注意 push -time
                    q.push(make_pair(-f[v][(j + 1) % k], v));
                }

            } else {
                /**
                 * 需要等待的情况：
                 *   在 t < a 时，下一次公交可以出发的时间是：
                 *
                 *   a, a+k, a+2k, a+3k, ...
                 *
                 *   我们需要找到 “>= t” 的最小的那一个时间。
                 *
                 *   等待时间 = ceil((a - t) / k) * k
                 *
                 *   例子：
                 *     t = 5, a = 12, k = 4
                 *     a - t = 7
                 *     ceil(7/4) = 2
                 *     wait = 2 * 4 = 8
                 *     所以你要等到 t + wait = 13（下一班车）
                 */

                int wait = ceil((a - t) * 1.0 / k) * k;

                if (f[u][j] + wait + 1 < f[v][(j + 1) % k]) {
                    f[v][(j + 1) % k] = f[u][j] + wait + 1;

                    q.push(make_pair(-f[v][(j + 1) % k], v));
                }
            }
        }
    }
}


int main() {
    freopen("3_in.txt", "r", stdin); 
    // freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;

    // 读入图
    int u, v, a;
    while (m--) {
        cin >> u >> v >> a;
        g[u].push_back(edge(v, a));
    }

    // 初始化 f 数组为无穷大
    memset(f, 0x3F3F3F3F, sizeof(f));

    // 起点城市 1，时间 t = 0，对应模 k = 0
    f[1][0] = 0;

    // 运行 Dijkstra
    djikstra();

    // 输出：到达城市 n、且时间 mod k = 0 的最短时间
    // 若不可达输出 -1
    if (f[n][0] == 0x3F3F3F3F) {
        cout << -1;
    } else {
        cout << f[n][0];
    }

    return 0;
}

/**
 * 编译运行：
 *   g++-14 -o main.out main_v2.cpp && ./main.out
 */
