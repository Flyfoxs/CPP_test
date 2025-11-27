#include <bits/stdc++.h>
using namespace std;

// 9437. 【2024年庐阳区初中区赛】最佳雇佣（hire）(3)

int main() {
    freopen("hire.in", "r", stdin);
    // freopen("hire.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    if(n > m){
        cout << -1 << endl;
        return 0;
    }

    for(long i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(m);
    for(long long i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 

    long long ans =0;
    long long pos = 0;
    long long count = 0;
    for(long long i = 0; i < n; i++) {
        for(long long j = pos; j < m; j++) {
            if(a[i] <= b[j]) {
                count++;
                ans = ans + b[j];
                // b[j] = -1;
                pos = j+1;
                break;
            }
        }
    }
    if(count != n){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
 
    
    return 0;
}

/**
 * g++-14 -o main.out main.cpp && ./main.out
 */