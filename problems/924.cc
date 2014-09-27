#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1000000000;

int main() {
	int n; scanf("%d", &n);
	vvi adj(n);
	for (int i = 0; i < n; ++i) {
		int j; scanf("%d", &j);
		while (j--) {
			int k; scanf("%d", &k);
			adj[i].push_back(k);
		}
	}

	int cases; scanf("%d", &cases);
	vi dist(n);
	while (cases--) {
		int s; scanf("%d", &s);
		dist.assign(n, INF);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		int diamax = 0, nummax = 0, ultimdia = 0, ultimnum = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if (u != s) {
				if (ultimdia == dist[u]) {
					++ultimnum;
				}
				else {
					ultimdia = dist[u];
					ultimnum = 1;
				}
				if (ultimnum > nummax) {
					nummax = ultimnum;
					diamax = ultimdia;
				}
			}
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				if (dist[v] == INF) {
					dist[v] = dist[u]+1;
					q.push(v);
				}
			}
		}
		if (diamax) printf("%d %d\n", nummax, diamax);
		else printf("0\n");
	}
}