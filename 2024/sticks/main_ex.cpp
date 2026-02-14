#include<bits/stdc++.h>
using namespace std;
// 9274：[CSP-J 2024] 小木棍（sticks）100 分
// https://www.luogu.com/article/xclxocjx
int stick[10]={6,2,5,5,4,5,6,3,7,6}; //先计算出每个数字需要的小木棍数量
int T,n;
int main(){
    freopen("sticks.in", "r", stdin);
    // freopen("sticks.out", "w", stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		} //特判
		int tmp=n,rem=(n+6)/7*7-n;
        //数的长度为(n+6)/7, 已经可以确定
        // tmp 表示还没有用的小木棍数量，rem 表示全为 8 的情况需要减去多少根木棍(需要补几根才行)
		while(tmp>0){
            cout << endl << "tmp=" << tmp << " rem=" << rem << endl;
			for(int i=0;i<10;i++){
                cout << "i=" << i << " tmp=" << tmp << " stick[i]=" << stick[i] << endl;
				if(tmp==n&&i==0) continue; //不能有前导零
				if(tmp<stick[i]) continue; //无法拼成这个数字
				//最后剩余的不能是1
				if(7-stick[i]<=rem&&tmp-stick[i]!=1){
					tmp=tmp-stick[i];
					rem=rem-(7-stick[i]);
					printf("%d",i);
					break;
				} //如果可以就选择，这一定是最小的
			}
		}
		printf("\n");
	}
	return 0;
}
/**
g++-14 -o main.out main_ex.cpp && ./main.out
*/