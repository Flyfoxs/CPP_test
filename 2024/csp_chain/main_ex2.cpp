#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int M=1e2+5;
vector<int> v[N];
int st[M][N];
int T,n,k,q;

int main() {
    freopen("chain.in", "r", stdin);
// freopen("chain.out", "w", stdout);
    cin>>T;
    while(T--) {
        memset(st,-1,sizeof st);
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1; i<=n; i++) {
            v[i].clear();
            int len;
            scanf("%d",&len);
            for(int j=1; j<=len; j++) {
                int t;
                scanf("%d",&t);
                v[i].push_back(t);
            }
        }

        st[0][1]=0;
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=n; j++) {
                int len=0;
                for(auto t:v[j]) {
                    len=max(len-1,0);
                    if(len) {
                        if(st[i][t]==-1) st[i][t]=j;
                        else if(st[i][t] && st[i][t]!=j) st[i][t]=0;
                    }
                    if(st[i-1][t]!=-1 && st[i-1][t]!=j) len=k;
                }
            }
        }

        while(q--) {
            int x,y;
            scanf("%d%d",&x,&y);
            if(st[x][y]!=-1) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;
}