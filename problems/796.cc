#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;

vi num, low, parent;
vii adj;
vpi links;
int cnt = 0, bridges = 0;

void dfs(int u) {
	num[u] = low[u] = cnt++;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (num[v] < 0) {
			parent[v] = u;

			dfs(v);

			if (low[v] > num[u]) {
				++bridges;
				if (u < v) links.push_back(pi(u,v));
				else links.push_back(pi(v,u));

			}
			low[u] = min(low[u], low[v]);
		}
		else if (parent[u] != v) {
			low[u] = min(low[u], num[v]);
		}
	}
}

int main() {
	int n;
	bool first = true;
	while (cin >> n) {
		adj = vii(n);
		for (int i = 0; i < n; ++i) {
			int k; cin >> k; int q;
			cin.ignore(2); cin >> q; cin.ignore();
			while (q--) {
				int j; cin >> j;
				adj[k].push_back(j);
			}
		}

		num = low = parent = vi(n, -1);
		cnt  = bridges = 0;
		links.clear();
		for (int i = 0; i < n; ++i) {
			if (num[i] < 0) dfs(i);
		}

		sort(links.begin(), links.end());


		cout << bridges << " critical links" << endl;
		for (int i = 0; i < bridges; ++i) {
			cout << links[i].first << " - " << links[i].second << endl;
		}
		cout << endl;
	}
}