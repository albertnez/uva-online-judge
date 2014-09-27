#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int c[101], v[101];
int memo[101][10205];

int f(int n, int m) {
	if (m > M+200) return -1;
	if (n == N) {
		if (m <= M) return 0;
		if (m > 2000) return 0;
		return -1;
	}
	if (memo[n][m] != -1) return memo[n][m];
	int& ans = memo[n][m];
	ans = f(n+1, m);
	int tmp = f(n+1, m+c[n]);
	if (tmp >= 0) return ans = max(ans, tmp + v[n]);
	return ans;
}


int main() {
	int m;
	while (scanf("%d %d", &M, &N) != EOF) {
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < N; ++i)
			scanf("%d %d", &c[i], &v[i]);
		printf("%d\n", f(0, 0));
	}
}