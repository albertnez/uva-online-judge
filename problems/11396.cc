#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi adj;
vi v;
bool dfs(int u, int c) {
	v[u] = c;
	for (int i = 0; i < adj[u].size(); ++i) {
		int a = adj[u][i];
		if (v[a] == -1 and !dfs(a, 1-c)) return false;
		else if (v[a] != -1 and v[a] == c) return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n and n) {
		v = vi(n+1, -1);
		adj = vvi(n+1);
		int a,b;
		while (cin >> a >> b and (a|b)) {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool pos = true;
		for (int i = 1; i <= n; ++i) 
			if (v[i] == -1 and !dfs(i, 1)) pos = false;
		cout << (pos ? "YES" : "NO") << endl;
	}
}