#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
//3203：【AHOI2021初中】坑（hole）（2）
//https://www.luogu.com.cn/problem/solution/P7622
struct Node{
	ll l;
	int id;
	bool operator <(const Node &T)const{
		return l<=T.l;
	}
} t[maxn];
ll n,m,ans=1e16;
ll a[maxn],b[maxn],r[maxn]; //a: Rats, b: Holes, r: Right Hole

int main()
{
    freopen("hole.in", "r", stdin);
    // freopen("hole.out", "w", stdout);
	cin>>n>>m;
	// n=read(),m=read();
	for (int i=1;i<=n;i++) cin>>a[i]; //Rats
	b[0]=-1e16;
	b[m+1]=1e16;
	for (int i=1;i<=m;i++) cin>>b[i]; //Holes
	sort(b+1,b+m+1);
	// cout<<"n="<<n<<" m="<<m<<endl;
	for (int i=1;i<=n;i++){
		// 找到第一个 > a[i] 的坑的位置下标
		int pos = upper_bound(b + 1, b + m + 1, a[i]) - b;

		// 最近的左侧坑在 pos - 1
		ll left_hole_pos = b[pos - 1];

		// 最近的右侧坑在 pos
		ll right_hole_pos = b[pos];

		// 向左走多少步可以掉进左坑
		t[i].l = a[i] - left_hole_pos;

		// 向右走多少步可以掉进右坑
		r[i] = right_hole_pos - a[i];

		// 记录老鼠原编号（因为后面要排序）
		t[i].id = i;


    }

	// for(int i=0;i<=n+1;i++){
	// 	printf("%15lld %15lld %4d\n", t[i].l, r[i], t[i].id);
	// }


    sort(t+1,t+n+1); //Rats

	// for(int i=0;i<=n+1;i++){
	// 	printf("%15lld %15lld %4d\n", t[i].l, r[i], t[i].id);
	// }
	// cout<<"rmax="<<rmax<<endl;
	ll rmax=0;
    for (int i=n;i>=0;i--){
    	ans=min(ans,min(t[i].l*2+rmax,rmax*2+t[i].l));
		// printf("ans=%lld rmax=%lld t[i].l=%lld t[i].id=%d\n", ans, rmax, t[i].l, t[i].id);
    	rmax=max(r[t[i].id],rmax); //记录没有被消灭的老鼠

		// printf("%15lld %15lld %15lld %4d\n", ans, rmax, t[i].l, t[i].id);
	}
	printf("%lld\n",ans);
	return 0;
}

/**
 g++-14 -o main.out main_ex.cpp && ./main.out

 */
