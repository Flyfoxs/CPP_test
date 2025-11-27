#include<bits/stdc++.h>
using namespace std;
/*====================*/
/*====================*/
using lnt = long long;
/*====================*/
const int N = 1e5 + 10;
const int R = 1e2 + 10;
const int C = 2e5 + 10;
/*====================*/
const int INF = 0X3F3F3F3F;
/*====================*/
int n, k, q;
vector<int>s[N];
int tag[R][C];//记录第r层，c结尾，是谁接龙的。
/*====================*/
void Insert(int r, int c, int id)
{
	if (tag[r][c] == -1)
	{
		tag[r][c] = id;
	}
	else if (tag[r][c] != id)
	{
		tag[r][c] = 0;
	}
}
/*====================*/
void Solve(void)
{
	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i)
	{
		int l; cin >> l; s[i].assign(l, 0);
		for (int j = 0; j < l; ++j)cin >> s[i][j];
	}
 
	memset(tag, -1, sizeof(tag)); tag[0][1] = 0;
 
	for (int turn = 1; turn <= 1e2; ++turn)
	{
		for (int i = 1; i <= n; ++i)
		{
			int head = -INF;
			for (int j = 0; j < s[i].size(); ++j)
			{
				if (head >= j - k + 1)Insert(turn, s[i][j], i);
				if (tag[turn - 1][s[i][j]] != -1 && tag[turn - 1][s[i][j]] != i)head = j;
			}
		}
	}
 
	for (int i = 1; i <= q; ++i)
	{
		int r, c; cin >> r >> c;
		cout << (tag[r][c] == -1 ? 0 : 1) << endl;
	}
}
/*====================*/
int main()
{
 
freopen("chain.in", "r", stdin);
// freopen("chain.out", "w", stdout);
cin.tie(NULL), cout.tie(NULL);
int T = 1; cin >> T;
while (T--)Solve();
return 0;
}

/**
 * 
 * g++-14 -o main.out main_ex.cpp && ./main.out
 */