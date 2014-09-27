#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<string> Vs;
const int INF = 1e9;
int main() {
	int n, m, ncase = 0;
	while (cin >> n >> m and (n|m)) {
		Vs names(n);
		Mi adj(n, Vi(n, INF));
		for (int i = 0; i < n; ++i) cin >> names[i];
		for (int i = 0; i < m; ++i) {
			int a, b, k;
			cin >> a >> b >> k; --a; --b;
			adj[a][b] = adj[b][a] = k;
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		int best = 1e9;
		int sol = 0;
		for (int i = 0; i < n; ++i) {
			int tmp = 0;
			for (int j = 0; j < n; ++j) if (j != i)
				tmp += adj[i][j];
			
			if (tmp < best) {
				best = tmp;
				sol = i;
			}
		}
		cout << "Case #" << ++ncase << " : " << names[sol] << endl;
	}
}