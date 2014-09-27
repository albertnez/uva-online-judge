#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<vector<pair<int,double> > > Mii;
typedef pair<double,ii> pi;
typedef vector<pi> Vpi;

Vi p, visited;
Mii adj;


int getp(int u) { return (p[u] < 0) ? u : p[u] = getp(p[u]); }
void join(int u, int v) {
	if (getp(u) !=  getp(v))
		p[getp(u)] = getp(v);
}

double dist(ii a, ii b) {
	return hypot(a.first-b.first, a.second-b.second);
}

bool dfs(int u, double& maxDist, int dest) {
	if (u == dest) return true;
	visited[u] = 1;
	for (int i = 0; i < int(adj[u].size()); ++i) {
		int v = adj[u][i].first;
		if (!visited[v] and dfs(v, maxDist, dest)) {
			maxDist = max(maxDist, adj[u][i].second);
			return true;	
		}
	}
	return false;
}

int main() {
	int n, cases = 0;
	while (scanf("%d", &n),n) {
		p.assign(n, -1);
		visited.assign(n, 0);
		Vpi edges;
		Vii loc(n);
		adj = Mii(n);
		for (int i = 0; i < n; ++i) {
			ii x; scanf("%d %d", &x.first, &x.second);
			loc[i] = x;
			for (int j = 0; j < i; ++j) {
				edges.push_back( pi(dist(x, loc[j]), ii(i, j)));
			}
		} 
		sort(edges.begin(), edges.end());
		for (int i = 0; i < int(edges.size()); ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) != getp(v)) {
				join(u,v);
				adj[u].push_back(make_pair(v, edges[i].first));
				adj[v].push_back(make_pair(u, edges[i].first));
			}
		}
		double maxDist = 0;
		dfs(0, maxDist, 1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cases, maxDist);
	}
}