#include<bits/stdc++.h>
using namespace std;
// 6247：[AHOI2023初中组]数数 (count)
int main() {
    freopen("count.in", "r", stdin);
    // freopen("count.out", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long ans = 0;

    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (a[i] + a[j] > a[k]) {
                ans += (j - i);
                j--;
            } else {
                i++;
            }
        }
    } 

    cout << ans << endl;
    return 0;
}
