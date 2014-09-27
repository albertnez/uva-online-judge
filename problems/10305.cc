#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void dfs (int k, vector<bool>& used, vii& adj, vi& top) {
	used[k] = true;
	for (int i = 0; i < int(adj[k].size()); ++i)
		if (!used[adj[k][i]]) dfs(adj[k][i], used, adj, top);
	top.push_back(k+1);
}

int main() {	
	int n, m;
	while (cin >> n >> m and n|m) {
		vector<bool> used(n, false);
		vii adj(n);
		while (m--) {
			int i, j; cin >> i >> j;
			adj[i-1].push_back(j-1);
		}
		vi top;
		
		for (int i = 0; i < n; ++i)
			if (!used[i]) dfs(i, used, adj, top);
		
		for (int i = n-1; i >= 0; --i)
			cout << top[i] << ' ';
		cout << endl;
	}
}
