#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
int INF = 1e9;
int main() {
	int cases; scanf("%d", &cases);
	for (int ncase = 1; ncase <= cases; ++ncase) {
		int n, m; scanf("%d %d", &n, &m);
		Mi adj(n, Vi(n, INF));
		for (int i = 0; i < n; ++i) adj[i][i] = 0;
		for (int i = 0; i < m; ++i) {
			int a,b; scanf("%d %d", &a, &b);
			adj[a][b] = 1;
			adj[b][a] = 1;
		}

		int s,d; scanf("%d %d", &s, &d);

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		int maxim = 0;
		for (int k = 0; k < n; ++k)
			maxim = max(maxim, adj[s][k]+adj[k][d]);
		
		printf("Case %d: %d\n", ncase, maxim);
	}
}