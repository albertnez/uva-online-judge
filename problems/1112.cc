#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<int> Vi;
typedef vector<Vii> Mii;

const int INF = 1000000000;

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, e, t, m;
		scanf("%d %d %d %d", &n, &e, &t, &m);
		--e;
		Mii adj(n);
		while (m--) {
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			--a; --b;
			adj[a].push_back(ii(b, w));
		}

		int total = 0;
		for (int k = 0; k < n; ++k) {
			Vi dist(n, INF);
			priority_queue<ii, vector<ii>, greater<ii> > q;
			dist[k] = 0;
			q.push(ii(0,k));
			while (!q.empty()) {
				int d = q.top().first, u = q.top().second; q.pop();
				if (u == e and d <= t) {
					++total;
					break;
				}
				if (d > dist[u]) continue;
				for (int i = 0; i < adj[u].size(); ++i) {
					ii v = adj[u][i];
					if (d + v.second < dist[v.first] and d+v.second <= t) {
						dist[v.first] = dist[u]+v.second;
						q.push(ii(dist[v.first], v.first));
					}
				}
			}
		}
		printf("%d\n", total);
		if (cases) printf("\n");
	}
}