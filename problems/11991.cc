#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

const int MAX = 1000001;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vii g(MAX, vi(0,0));
		for (int i = 1; i <= n; ++i) {
			int k; cin >> k;
			g[k].push_back(i);
		}
		for (int i = 0; i < m; ++i) {
			int k, v; cin >> k >> v;
			if (k > g[v].size()) cout << 0 << endl;
			else cout << g[v][k-1] << endl;
		}
	}
}