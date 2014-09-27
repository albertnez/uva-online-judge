#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> Vii;

int N;
int INF = 1e9;
int dist[11][11];
int memo[11][1<<12];
int f(int pos, int mask) {
	if (mask == (1<<N)-1) return dist[pos][0];
	if (memo[pos][mask] != -1) return memo[pos][mask];

	int sol = INF;
	for (int i = 1; i < N; ++i) {
		if (!((1<<i)&mask))
			sol = min(sol, f(i, mask|(1<<i)) + dist[pos][i]);
	}
	return memo[pos][mask] = sol;
}

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		memset(memo, -1, sizeof memo);
		int mj, mi; scanf("%d %d", &mj, &mi);
		Vii pos(11);
		scanf("%d %d", &pos[0].first, &pos[0].second);
		scanf("%d", &N); ++N;

		for (int i = 1; i < N; ++i) {
			scanf("%d %d", &pos[i].first, &pos[i].second);
			for (int j = 0; j < i; ++j)
				dist[i][j] = dist[j][i] = (abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second));
		}
		
		printf("The shortest path has length %d\n", f(0, 1));
	}
}