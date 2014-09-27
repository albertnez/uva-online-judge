#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> mii;

int main() {
	int n, m;
	while (cin >> n >> m) {
		mii g(m);
		for (int row = 1; row <= n; ++row) {
			int r; cin >> r;
			vi v(r);
			for (int i = 0; i < r; ++i) cin >> v[i];
			for (int i = 0; i < r; ++i) {
				int k; cin >> k;
				g[v[i]-1].push_back(make_pair(row, k));
			}
		}

		cout << m << ' ' <<  n << endl; 
		for (int i = 0; i < m; ++i) {
			cout << g[i].size();
			for (int j = 0; j < g[i].size(); ++j) cout << ' ' << g[i][j].first;
			cout << endl;
			for (int j = 0; j < g[i].size(); ++j) cout << (j?" ":"") << g[i][j].second;
			cout << endl;
		}
	}
}