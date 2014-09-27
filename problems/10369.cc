#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef pair<double,ii> pi;
typedef vector<pi> Vpi;
typedef vector<ii> Vii;

Vi p;

int getp(int u) { return (p[u] < 0) ? u : p[u] = getp(p[u]); }
void join(int u, int v) { if (getp(u) != getp(v)) p[getp(u)] = getp(v); }

double dist(ii a, ii b) { return hypot(a.first-b.first, a.second-b.second); }

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int s,n;
		Vpi edges;
		scanf("%d %d", &s, &n);
		Vii loc(n);
		p.assign(n, -1);
		for (int i = 0; i < n; ++i) {
			ii pos; scanf("%d %d", &pos.first, &pos.second);
			loc[i] = pos;
			for (int j = 0; j < i; ++j) {
				double d = dist(pos, loc[j]);
				edges.push_back(pi(d, ii(i, j)));
			}
		}
		sort(edges.begin(), edges.end());
		int cc = n;
		double totaldist = 0;
		for (int i = 0; cc > s; ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) != getp(v)) {
				join(u,v);
				if (edges[i].first > totaldist) totaldist = edges[i].first;
				--cc;
			}
		}
		printf("%.2lf\n", totaldist);
	}
}