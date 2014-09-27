#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> pi;
typedef vector<pi> vpi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi p, visited;
vvi adj, weight;
//Mii adj;

int getp(int u) { return (p[u] < 0 ? u : p[u]=getp(p[u])); }
void join(int u, int v) {
	if (getp(u) != getp(v)) p[getp(u)] = v;
}


bool dfs(int u, int &maxim, int s) {
	if (u == s) return true;
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!visited[v] and dfs(v, maxim, s)) {
			maxim = max(maxim, weight[u][i]);
			return true;
		}
	}
	return false;
}

int main() {
	int n,m,q, ncase = 0;
	while (scanf("%d %d %d", &n, &m, &q), (n||m||q)) {
		p.assign(n, -1);
		weight = vvi(n);
		vpi edges(n);
		adj = weight = vvi(n);
		edges = vpi(m);
		for (int i = 0; i < m; ++i) {
			pi x; scanf("%d %d %d", &x.second.first, &x.second.second, &x.first);
			--x.second.first; --x.second.second;
			edges[i] = x;
		}
		sort(edges.begin(), edges.end());

		for (int i = 0; i < m; ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) != getp(v)) {
				join(u, v);
				adj[u].push_back(v); weight[u].push_back(edges[i].first);
				adj[v].push_back(u); weight[v].push_back(edges[i].first);
			}
		}

		if (ncase) printf("\n");
		printf("Case #%d\n", ++ncase);
		while (q--) {
			visited.assign(n, 0);
			int u, v; scanf("%d %d", &u, &v);
			int maxim = 1<<31;
			if (dfs(u-1, maxim, v-1)) printf("%d\n", maxim);
			else printf("no path\n");
		}
	}
}