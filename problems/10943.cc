#include <cstdio>
#include <cstring>
using namespace std;

int N, K;
int mod = 1e6;
int memo[101][101];

int f(int n, int k) {
	if (n == N and k == 0) return 1;
	if (n > N or k < 0) return 0;
	if (memo[n][k] != -1) return memo[n][k];
	int ans = 0;
	for (int i = 0; i <= N; ++i)
		ans = (ans+f(n+i, k-1))%mod;
	return memo[n][k] = ans;
}

int main() {
	while (scanf("%d %d", &N, &K), N|K) {
		memset(memo, -1, sizeof memo);
		printf("%d\n", f(0, K));
	}
}