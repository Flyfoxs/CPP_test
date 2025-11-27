#include<bits/stdc++.h>
const int INF = 1e9;
const int N = 2e5+5;
void solve() {
	int n,k,q;
	std::cin>>n>>k>>q;
	std::vector<std::vector<int>> dp(100+1,std::vector<int>(N,-1)); 
	std::vector<std::vector<int>> s(n+1);
	
	dp[0][1]=-2;
	
	for(int i=1;i<=n;i++) {
		int len;
		std::cin>>len;
		s[i].resize(len);
		for(auto &v:s[i])
			std::cin>>v;
	}
	
	for(int cnt=1;cnt<=100;cnt++) {
		for(int i=1;i<=n;i++) {
			int lst=-1;
			for(int j=0;j<s[i].size();j++) {
				
				int x = s[i][j];
				
				if(lst!=-1 && (j-lst+1<=k)) {
					if(dp[cnt-1][s[i][lst]]!=-1&&dp[cnt-1][s[i][lst]]!=i) {
						
						if(dp[cnt][x]==-1)
							dp[cnt][x] = i;
							
						else if(dp[cnt][x]!=i)
							dp[cnt][x] = -2;
					}
				}
				int v = dp[cnt-1][x];
				if(v!=-1 && v!= i ) {
					lst=j;
				}
					
			}
		}
		
	}
	
	while(q--) {
		int r,c;
		std::cin>>r>>c;
		std::cout<< ((dp[r][c]!=-1)? 1 : 0 )<<"\n";
	}
	
}
int main()
{
    freopen("chain.in", "r", stdin);
// freopen("chain.out", "w", stdout);
	int T=1;
	std::cin>>T;
	while(T--)
		solve();
}
