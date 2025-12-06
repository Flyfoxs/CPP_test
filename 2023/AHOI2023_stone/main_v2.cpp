#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);
// 6249. [AHOI2023初中组]石子(stone)
int main() {
	freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);

    int n, l, r;
    if (!(cin >> n >> l >> r)) return 0;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> answers;
    answers.reserve(r - l + 1);

    for (int s = l; s <= r; ++s) {
        int p = s - 1;         // left count
        int q = n - s;         // right count

        // build L[1..p], R[1..q] (nearest first)
        vector<ll> L(p+1), R(q+1);
        for (int i = 1; i <= p; ++i) L[i] = a[s - i];
        for (int j = 1; j <= q; ++j) R[j] = a[s + j];

        // 2D DP: dp[0..p][0..q]
        // dp[i][j] = minimal weighted sum (excluding (n-1)*a[s]) after taking i from left and j from right
        vector<vector<ll>> dp(p+1, vector<ll>(q+1, INF));
        dp[0][0] = 0;

        for (int i = 0; i <= p; ++i) {
            for (int j = 0; j <= q; ++j) {
                if (dp[i][j] >= INF) continue;
                int pos = i + j; // already taken
                if (i < p) {
                    ll coef = (ll)(n - (pos + 1));
                    ll cand = dp[i][j] + coef * L[i+1];
                    if (cand < dp[i+1][j]) dp[i+1][j] = cand;
                }
                if (j < q) {
                    ll coef = (ll)(n - (pos + 1));
                    ll cand = dp[i][j] + coef * R[j+1];
                    if (cand < dp[i][j+1]) dp[i][j+1] = cand;
                }
            }
        }

        ll best = dp[p][q];
        ll total = (ll)(n - 1) * a[s] + best;
        answers.push_back(total);
    }

    for (int i = 0; i < (int)answers.size(); ++i) {
        if (i) cout << ' ';
        cout << answers[i];
    }
    cout << '\n';
    return 0;
}
