#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,ii> pi;
typedef vector<pi> vpi;
typedef vector<ii> vii;


vi sp, cp;

int getsp(int a) { return (sp[a] < 0 ? a : sp[a] = getsp(sp[a])); }
void joins(int u, int v) {
	int a = getsp(u), b = getsp(v);
	if (a == b) return;
	else sp[a] = b;
}

int getcp(int a) { return (cp[a] < 0 ? a : cp[a] = getcp(cp[a])); }
void joinc(int u, int v) {
	int a = getcp(u), b = getcp(v);
	if (a == b) return;
	else cp[a] = b;
}

double dist(ii a, ii b) {
	return hypot(a.first-b.first, a.second-b.second);
}


int main() {
	int cases; scanf("%d", &cases);
	int ncases = 0;
	while (cases--) {
		int n, r; scanf("%d %d", &n, &r);
		sp.assign(n, -1);
		cp.assign(n, -1);
		vii loc(n);
		vpi edges;
		int states = n;
		for (int i = 0; i < n; ++i) {
			ii c; scanf("%d %d", &c.first, &c.second);
			for (int j = 0; j < i; ++j) {
				double d = dist(loc[j], c);
				edges.push_back(make_pair(d, ii(i, j)));
				if (getsp(i) != getsp(j) and d <= r) {
					joins(i, j);
					--states;
				}
			}
			loc[i] = c;
		}
		sort(edges.begin(), edges.end());
		double icost = 0, lcost = 0;
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getcp(u) != getcp(v)) {
				joinc(u, v);
				if (getsp(u) == getsp(v)) lcost += edges[i].first;
				else icost += edges[i].first;
			}
		}
		printf("Case #%d: %d %.0lf %.0lf\n", ++ncases, states, lcost, icost);  
	}
}