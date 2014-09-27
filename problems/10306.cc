#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;


int memo[310][310];
int coins[45][2];
int S, M, S2;
int INF = 1e9;

int f(int x, int y) {
	if (x*x+y*y == S2) return memo[x][y] = 0;
	if (x*x+y*y > S2) return INF;
	if (memo[x][y] != INF) return memo[x][y];
	int minim = INF; for (int i = 0; i < M; ++i) minim = min(minim, f(x+coins[i][0],y+coins[i][1]));
	return memo[x][y] = 1 + minim;
}
int main() {
	int n; scanf("%d", &n);
	while (n--) {
		//memset(memo, 1, sizeof (int));
		for (int i = 0; i < 310; ++i) for (int j = 0; j < 310; ++j) memo[i][j] = INF;
		//printf("memo: %d\n", memo[0][0][0]);
		scanf("%d %d", &M, &S);
		S2 = S*S;
		for (int i = 0; i < M; ++i)
			scanf("%d %d", &coins[i][0], &coins[i][1]);

		int ans = f(0, 0);
		if (ans < INF) printf("%d\n", ans);
		else printf("not possible\n");
	}
}
