#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
int INF = 1e9;

void print(int i, int j, Mi& p) {
	if (i != j) print(i, p[i][j], p);
	printf(" %d", j);
}

int main() {
	int n, ncase = 0;
	while (scanf("%d", &n),n) {
		Mi adj(n+1, Vi(n+1,INF)), path(n+1, Vi(n+1));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				path[i][j] = i;

		for (int i = 1; i <= n; ++i) {
			adj[i][i] = 0;
			int num; scanf("%d", &num);
			while (num--) {
				int j, c; scanf("%d %d", &j, &c);
				adj[i][j] = c;
			}
		}

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j) {
					if (adj[i][k] + adj[k][j] < adj[i][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						path[i][j] = path[k][j];
					}
				}

		int s,d; scanf("%d %d", &s, &d);
		printf("Case %d: Path =", ++ncase); print(s,d,path); printf("; %d second delay\n", adj[s][d]);
	}
}