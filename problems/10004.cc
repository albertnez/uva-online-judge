#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;


bool dfs(int v, bool state, const vii& adj, vi& c) {
	c[v] = state+1;
	state = !state;
	bool ret = true;
	for (int i = 0; i < adj[v].size(); ++i) {
		if (!c[adj[v][i]]) ret = dfs(adj[v][i], state, adj, c);
		else if (c[adj[v][i]]-1 != state) return false;
	}
	return ret;
}

int main() {
	int n;
	while (cin>>n and n) {
		int e; cin >> e;
		vii adj(n);
		vi c(n, 0);
		while (e--) {
			int a,b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if (dfs(0, true, adj, c)) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}
}