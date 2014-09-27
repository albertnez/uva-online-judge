#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

vii adj;
vi dfs_low, dfs_num, dfs_parent;
vector<bool> art;
int dfsCounter, root, rootChildren;
int nart = 0;

void dfs(int u) {
	dfs_low[u] = dfs_num[u] = dfsCounter++;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfs_num[v] < 0) { //Not visited
			dfs_parent[v] = u;
			if (u == root) ++rootChildren;

			dfs(v);

			if (dfs_low[v] >= dfs_num[u]) art[u] = true;
			
			if (dfs_low[v] < dfs_low[u]) dfs_low[u] = dfs_low[v];
		}
		else if (v != dfs_parent[u] and dfs_num[v] < dfs_low[u])
			dfs_low[u] = dfs_num[v];
	}
}


int main() {
	int n;
	while (cin >> n and n) {
		adj = vii(n);
		int k;
		while (cin >> k and k) {
			--k;
			string s; getline(cin,s);
			istringstream ss(s);
			int q;
			while (ss>>q) {
				--q;
				adj[k].push_back(q);
				adj[q].push_back(k);
			}
		}



		dfs_low = dfs_num = dfs_parent = vi(n, -1);
		art.assign(n, false);
		dfsCounter = 0;
		nart = 0;
		for (int i = 0; i < n; ++i) {
			root = i;
			rootChildren = 0;
			if (dfs_num[i] == -1) {
				dfs(i);
				art[i] = (rootChildren > 1);
			}
		}


		for (int i = 0; i < n; ++i) {
			if (art[i]) ++nart;
		}
		cout  << nart << endl;
	}
}