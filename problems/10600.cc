#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> pi;
typedef vector<pi> vpi;

vi p;
int getp(int u) { 
	return (p[u] < 0) ? u : p[u] = getp(p[u]); 
}
void join(int u, int v) {
	if (getp(u) != getp(v))
		p[getp(u)] = getp(v);
}

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, m; scanf("%d %d", &n, &m);
		vpi edges(m);
		for (int i = 0; i < m; ++i) {
			int a,b,w; scanf("%d %d %d", &a, &b, &w);
			edges[i] = pi(w, ii(a-1,b-1));
		}
		sort(edges.begin(), edges.end());

		vi taken(n-1);
		int idx = 0;
		p.assign(n, -1);
		int mincost = 0;
		for (int i = 0; i < m; ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) != getp(v)) {
				join(u, v);
				mincost += edges[i].first;
				taken[idx++] = i;
			}
		}	
		//second best mst	
		int secondbest = 1000000000;
		for (int k = 0; k < n-1; ++k) {
			int cost = 0;
			p.assign(n, -1);
			int cc = n;
			for (int i = 0; i < m; ++i) {
				if (taken[k] == i) continue;
				int u = edges[i].second.first, v = edges[i].second.second;
				if (getp(u) != getp(v)) {
					join(u, v);
					--cc;
					cost += edges[i].first;
				}
			}	
			if (cc == 1 and cost < secondbest)
				secondbest = cost;
		}
		if (m == n-1) secondbest = mincost;
		printf("%d %d\n", mincost, secondbest);
	}
}