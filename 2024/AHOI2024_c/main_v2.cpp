//冷静，冷静，冷静
//调不出来就重构 
// https://blog.csdn.net/qq_74190237/article/details/139241576
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> pii;
const int N=1e6+10,mod=1e4+7;
ll f[N],p[N];
struct node
{
	ll cz,x,y;
}op[N];
int main()
{
    // freopen("c.in", "r", stdin);
    freopen("3_in.txt", "r", stdin);
    // freopen("c.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		ll v;cin>>v;
		p[v]++;p[v-1]--;//记录当前机器被使用 
	}
	for(int i=1;i<=m;i++)
	{
		cin>>op[i].cz>>op[i].x>>op[i].y;
	}
	ll now=0;
	for(int i=m;i;i--)
	{
		now+=p[i];//当前机器的使用次数 
		if(op[i].cz==1)//如果是操作一，就直接对数组操作 
		{
			f[op[i].x]+=op[i].y*now;//操作次数乘上一次操作加的数 
			f[op[i].x]=f[op[i].x]%=mod;
		}
		else//第二种操作 
		{
			p[op[i].x-1]-=now;p[op[i].x-1]=p[op[i].x-1]%mod+mod;p[op[i].x-1]%=mod;//now为当前机器的操作次数，那么利用差分，就可以让x->y这一部分的机器操作now次 
			p[op[i].y]+=now;p[op[i].y]%=mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<' ';
	}
    return 0;
}

/**
 * 编译运行：
 *   g++-14 -o main.out main_v2.cpp && ./main.out
 */