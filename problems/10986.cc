#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<Vii> Mii;
typedef vector<int> Vi;
const int INF = 1000000000;
Vi dist;


int main() {
	int cases; scanf("%d", &cases);
	for (int ncas = 1; ncas <= cases; ++ncas) {
		int n, m, s, t;
		scanf("%d %d %d %d", &n, &m, &s, &t);
		Mii adj(n);
		while (m--) {
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			adj[a].push_back(ii(b,w));
			adj[b].push_back(ii(a,w));
		}

		//dijkstra
		dist.assign(n, INF);
		dist[s] = 0;
		priority_queue<ii> q; q.push(ii(0, s));
		int total = INF;
		while (!q.empty()) {
			ii front = q.top(); q.pop();
			int d = -front.first, u = front.second;
			if (d > dist[u]) continue;

			if (u == t and dist[u] < total) {
				total = dist[u];
				break;
			}


			for (int i = 0; i < adj[u].size(); ++i) {
				ii v = adj[u][i];
				if (d+v.second < dist[v.first]) {
					dist[v.first] = d+v.second;
					q.push(ii(-dist[v.first], v.first));
				}
			}
		}
		if (total == INF) printf("Case #%d: unreachable\n", ncas);
		else printf("Case #%d: %d\n", ncas, total);
	}
}