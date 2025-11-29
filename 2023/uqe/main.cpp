#include <bits/stdc++.h>
using namespace std;

//9437. 【2024年庐阳区初中区赛】最佳雇佣（hire）(3) 
int gcd(int a, int b)//求a、b的最大公约数 
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
void showNum(int x, int y)//输出有理数x/y
{
	if(x*y < 0)
		printf("-");
	int a = abs(x), b = abs(y), g = gcd(a, b);
	a /= g, b /= g;//约分 
	if(b == 1)
		printf("%d", a);
	else
		printf("%d/%d", a, b);
} 
void showMultSqrt(int x, int y, int r)//输出有理数x/y乘以sqrt(r)（保证x不为0，且x*y>0） 
{
	int a = abs(x), b = abs(y), g = gcd(a, b);
	a /= g, b /= g;
	if(a == 1 && b == 1)
		printf("sqrt(%d)", r);
	else if(b == 1)
		printf("%d*sqrt(%d)", a, r); 
	else if(a == 1)
		printf("sqrt(%d)/%d", r, b);
	else
		printf("%d*sqrt(%d)/%d", a, r, b);
}

int maxFac(int x)//求满足i*i是x的约数的最大的i 
{
	for(int i = sqrt(x); i >= 1; --i)
		if(x%(i*i) == 0)
			return i;
    return 1;
} 

void solve(int a, int b, int c)
{
	if(a < 0)//如果a<0，则a、b、c都取相反数，保证a>0 
		a = -a, b = -b, c = -c;
	int delta = b*b-4*a*c;
	if(delta < 0)
		printf("NO");
	else
	{
		int sd = sqrt(delta);//delta开根号的结果
		if(sd*sd == delta)//delta是完全平方数，方程的根中无根号
			showNum(-b+sd, 2*a); 
		else//有根号 
		{
			if(b != 0)//有前一项
			{
				showNum(-b, 2*a);
				printf("+");
			}
			int mf = maxFac(delta);
			showMultSqrt(mf, 2*a, delta/(mf*mf));
		}
	}
	printf("\n");
}
int main()
{
    freopen("uqe.in", "r", stdin);
    // freopen("uqe.out", "w", stdout);
	int t, m, a, b, c;
	scanf("%d %d", &t, &m);
	while(t--)
	{
		scanf("%d %d %d", &a, &b, &c);
		solve(a, b, c);
	}
	return 0;
}

/**
 * 
 * g++-14 -o main.out main.cpp && ./main.out
 */