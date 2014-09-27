#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> pi;
typedef vector<pi> vpi;


vi p;
int getp(int u) { return (p[u] < 0 ? u : p[u]=getp(p[u])); }
void join(int u,int v) {
	if (getp(u) != getp(v)) p[getp(u)] = v;
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m), (n||m)) {
		vpi edges;
		p.assign(n, -1);

		for (int i = 0; i < m; ++i) {
			pi x; scanf("%d %d %d", &x.second.first, &x.second.second, &x.first);
			edges.push_back(x);
		}
		sort(edges.begin(), edges.end());
		vi notused;
		for (int i = 0; i < m; ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) == getp(v)) notused.push_back(edges[i].first);
			else join(u, v);
		}
		if (notused.size() > 0) printf("%d", notused[0]);
		else printf("forest");
		for (int i = 1; i < notused.size(); ++i) printf(" %d", notused[i]);
		printf("\n");
	}
}