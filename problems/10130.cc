#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int price[1005], weight[1005];
int memo[1005][35];
int N, G;
int val(int id, int remW) {
	if (remW == 0 | id == N) return 0;
	if (memo[id][remW] != -1) return memo[id][remW];
	if (weight[id] > remW) return memo[id][remW] = val(id+1, remW);
	return memo[id][remW] = max(val(id+1, remW), price[id] + val(id+1, remW-weight[id]));
}

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		memset(memo, -1, sizeof memo);
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d %d", &price[i], &weight[i]);
		scanf("%d", &G);
		int sum = 0;
		while (G--) {
			int w; scanf("%d", &w);
			sum += val(0, w);
		}
		printf("%d\n", sum);
	}
}