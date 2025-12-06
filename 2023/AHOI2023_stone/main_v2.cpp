#include <iostream>
#define int long long
int N, L, R;
int Arr[5005], SumArr[5005], NoteBook[5005][5005];

int Sum(int l, int r) {
    //从l到r的和
	return SumArr[r] - SumArr[l - 1];
}

int DFS(int l, int r) {
    //已合并区间是[l, r]
	int Min = 0x7F7F7F7F7F7F7F7F; //最小值
	if (NoteBook[l][r] != 0) {
        //记忆化(不加20分)
		return NoteBook[l][r];
	}
	if (l - 1 >= 1) {
		//左边还有，合并左边
		Min = std::min(Min, DFS(l - 1, r) + Sum(l, r) + Arr[l - 1]);
	}
	if (r + 1 <= N) {
		//右边还有，合并右边
		Min = std::min(Min, DFS(l, r + 1) + Sum(l, r) + Arr[r + 1]);
	}
	if (l == 1 && r == N) {
        //边界条件：都合并好了
		Min = 0;
	}
	NoteBook[l][r] = Min; //记录
	return Min;
}

signed main() {
    freopen("stone.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
	std::cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		std::cin >> Arr[i];
		SumArr[i] = SumArr[i - 1] + Arr[i]; //前缀和
	}
	for (int i = L; i <= R; i++) {
		std::cout << DFS(i, i) << ' '; //输出(一开始已合并区间是从i到i的)
	}
	std::cout << '\n';
	return 0;
}

/**
 * g++-14 -o main.out main_v2.cpp && ./main.out
 */