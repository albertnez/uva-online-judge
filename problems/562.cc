#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int S, M;
int coins[105];
int memo[105][50010];

int INF = 1e9;

int f(int id, int sum) {
	if (id >= M) return abs(S-2*sum);
	if (memo[id][sum] != INF) return memo[id][sum];
	return memo[id][sum] = min ( f(id+1, sum+coins[id]), f(id+1, sum)  );
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		for (int i = 0; i < 105; ++i) for (int j = 0; j < 50010; ++j) memo[i][j] = INF;
		scanf("%d", &M);
		S = 0;
		for (int i = 0; i < M; ++i) {
			scanf("%d", &coins[i]);
			S += coins[i];
		}
		printf("%d\n", f(0,0));	
	}
}