#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cuts[52];
int memo[52][52];

int f(int l, int r) {
	if (l+1 == r) return 0;
	if (memo[l][r] != -1) return memo[l][r];
	int ans = 1e9;
	for (int i = l+1; i < r; ++i)
		ans = min(ans, f(l,i)+f(i,r)+cuts[r]-cuts[l]);
	return memo[l][r] = ans;
}

int main() {
	cuts[0] = 0;
	int l;
	while(scanf("%d", &l),l) {
		memset(memo, -1, sizeof memo);
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &cuts[i]);
		cuts[n+1] = l;
		printf("The minimum cutting is %d.\n", f(0, n+1));

	}
}