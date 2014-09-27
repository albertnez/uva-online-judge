#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int coins[5] = {1, 5, 10, 25, 50};

ll memo[10][30010];

ll f(int n, int k) {
	if (k == 0) return 1;
	if (n == 5 or k < 0) return 0;
	if (memo[n][k] != -1) return memo[n][k];
	return memo[n][k] = f(n+1, k) + f(n, k-coins[n]);
}

int main() {
	memset(memo, -1, sizeof memo);
	int k;
	while (scanf("%d", &k) != EOF) {
		ll ans = f(0, k);
		if (ans == 1) printf("There is only 1 way to produce %d cents change.\n", k);
		else printf("There are %lld ways to produce %d cents change.\n", ans, k);
	}
}