#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vi parent, articulation, num, low;
vvi adj;
int nvertex, root, children;

void dfs(int u) {
	num[u] = low[u] = nvertex++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (num[v] < 0) {
			parent[v] = u;
			if (u == root) ++children;

			dfs(v);

			if (low[v] >= num[u])
				++articulation[u];

			low[u] = min(low[u], low[v]);

		}
		else if (parent[u] != v)
			low[u] = min(low[u], num[v]);
	}
}


int main() {
	int n, m;
	while (cin >> n >> m and (n or m)) {
		adj = vvi(n);
		parent = articulation = low = vi(n, 0);
		num = vi(n, -1);
		int a,b;
		while (cin >> a >> b and a != -1 and b != -1) {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

/*
		for (int i = 0; i < n; ++i) {
			cout << endl << i << " |";
			for (int j = 0; j < adj[i].size(); ++j) {
				cout << ' ' << adj[i][j];
			}
		}
		cout << endl;
*/
		for (int i = 0; i < n; ++i) {
			if (num[i] < 0) {
				root = i;
				children = 0;
				dfs(i);
				articulation[i] = children-1;
			}
		}


		vector<pair<int,int> > vpi;
	
		for (int i = 0; i < n; ++i)
			vpi.push_back(make_pair(-articulation[i], i));
		sort(vpi.begin(), vpi.end());
		for (int i = 0; i < m; ++i) cout << vpi[i].second << ' ' << -vpi[i].first+1 <<  endl;
		cout << endl;

	}

}