#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
/*
***************************
******** TOP DOWN *********
***************************
int M, C, price[25][25];
int memo[210][25];

int INF = 1e9;



int shop(int money, int g) {
	if (money < 0) return -INF;
	if (g == C) return M - money;
	if (memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for (int model = 1; model <= price[g][0]; ++model) 
		ans = max(ans, shop(money-price[g][model], g+1));
	return memo[money][g] = ans;
	
}

int main() {
	int ncase; scanf("%d", &ncase);
	while (ncase--) {
		scanf("%d %d", &M, &C);
		for (int i = 0; i < C; ++i) {
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; ++j)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof memo);
		int ans = shop(M, 0);
		if (ans < 0) printf("no solution\n");
		else printf("%d\n", ans);
	}
}
*/

//***************
//***BOTTOM-UP***
//***************

int main() {
	int g, money, k, TC, M, C;
	int price[25][25];
	bool reachable[25][210];
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &M, &C);
		for (int i = 0; i < C; ++i) {
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; ++j)
				scanf("%d", &price[i][j]);
		}
		memset(reachable, false, sizeof reachable);
		for (int i = 1; i <= price[0][0]; ++i)
			if (M-price[0][i] >= 0) reachable[0][M-price[0][i]] = true;

		for (g = 1; g < C; ++g) {
			for (money = 0; money < M; ++money) {
				if (reachable[g-1][money])
					for (k = 1; k <= price[g][0]; ++k)
						if (money-price[g][k] >= 0) reachable[g][money-price[g][k]] = true;
			}
		}
		for (money = 0; money <= M and !reachable[C-1][money]; money++);

		if (money == M+1) printf("no solution\n");
		else printf("%d\n", M - money);
	}
}