#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int INF = 1e9;

int main() {
	int n, ncase = 0;
	while (scanf("%d", &n) != EOF) {
		Mi adj(21, Vi(21, INF));
		for (int i = 0; i < n; ++i) {
			int a; scanf("%d", &a); adj[1][a] = adj[a][1] = 1;
		}
		for (int i = 2; i < 20; ++i) {
			int num; scanf("%d", &num);
			while (num--) {
				int a; scanf("%d", &a);
				adj[i][a] = adj[a][i] = 1;
			}
		}

		for (int k = 0; k < 21; ++k)
			for (int i = 0; i < 21; ++i)
				for (int j = 0; j < 21; ++j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		int pairs; scanf("%d", &pairs);
		printf("Test Set #%d\n", ++ncase);
		while (pairs--) {
			int a, b; scanf("%d %d", &a, &b);
			printf("%2d to %2d: %d\n", a, b, adj[a][b]);
		}
		printf("\n");
	}
}