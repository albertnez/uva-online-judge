#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<Vii> Mii;

const int INF = 1e9;

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, m; scanf("%d %d", &n, &m);
		Mii adj(n);
		while (m--) {
			int a,b,w; scanf("%d %d %d", &a, &b, &w);
			adj[a].push_back(ii(b,w));
		}
		Vi dist(n, INF); dist[0] = 0;
		for (int i = 0; i < n-1; ++i) 
			for (int u = 0; u < n; ++u) 
				for (int j = 0; j < adj[u].size(); ++j) {
					ii v = adj[u][j];
					dist[v.first] = min(dist[v.first], dist[u]+v.second);
				}
		bool pos = false;
		for (int u = 0; u < n; ++u)
			for (int i = 0; i < adj[u].size(); ++i) {
				ii v = adj[u][i];
				if (dist[u]+v.second < dist[v.first])
					pos = true;
			}
		if (pos) printf("possible\n");
		else printf("not possible\n");
	}
}