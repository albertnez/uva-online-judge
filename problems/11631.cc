#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi parent;

int getp(int u) {
	if (parent[u] < 0) return u;
	else return parent[u] = getp(parent[u]);
}

void join(int u, int v) {
	int a = getp(u), b = getp(v);
	if (a == b) return;
	else parent[a] = b;
}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m), (m||n)) {
		vector<pair<int,ii> > edges;
		int precost = 0, cost = 0, components = n;
		parent.assign(n, -1);

		for (int i = 0; i < m; ++i) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			edges.push_back(make_pair(c, ii(a,b)));
			precost += c;
		}
		sort(edges.begin(), edges.end());
		for (int i = 0; i < edges.size() and components > 1; ++i) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if (getp(u) != getp(v)) {
				join(u, v);
				--components;
				cost += edges[i].first;
			}
		}
		printf("%d\n", precost-cost);
	}
}