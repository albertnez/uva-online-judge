#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int coins[101];
int memo[101][20010];
int used[101][20010];

int INF = 1e9;

int f(int n, int m) {
	if (m >= M) {
		used[n][m] = 0;
		return 0;
	}
	if (n == N) return INF;

	if (memo[n][m] != -1) return memo[n][m];

	int a = f(n+1, m);
	int b = f(n+1, m+coins[n]) + coins[n];
	if (a < b) used[n][m] = used[n+1][m];
	else if (b < a) used[n][m] = used[n+1][m+coins[n]] + 1;
	else used[n][m] = min(used[n+1][m], used[n+1][m+coins[n]] + 1);
	return memo[n][m] = min(a,b);
}



int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		memset(memo, -1, sizeof memo);

		scanf("%d", &M);
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &coins[i]);

		int ans = f(0,0);
		printf("%d %d\n", ans, used[0][0]);
	}
}