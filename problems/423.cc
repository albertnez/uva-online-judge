#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;

int stoi(string s) {
	int n = 0;
	for (int i = 0; i < s.size(); ++i) {
		n *= 10;
		n += s[i]-'0';
	}
	return n;
}

int main() {
	int n; cin >> n;
	VVI adj(n, VI(n, INF));
	for (int i = 1; i < n; ++i) for (int j = 0; j < i; ++j) {
		string s; cin >> s;
		if (s != "x") adj[i][j] = adj[j][i] = stoi(s); 
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int sol = 0;
	for (int i = 1; i < n; ++i)
		sol = max(sol, adj[0][i]);
	cout << sol << endl;
}