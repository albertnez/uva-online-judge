#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> Vii;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

typedef vector<double> Vd;
typedef vector<Vd> Md;

double dist(ii a, ii b) {
	return hypot(a.first-b.first, a.second-b.second);
}

const double INF = 1e20;

int main() {
	int T, ncase = 0; cin >> T;
	cout.precision(4);
	while (T--) {
		int n; cin >> n;
		Vii pos(n);
		Md adj(n, Vd(n, INF));

		for (int i = 0; i < n; ++i) {
			cin >> pos[i].first >> pos[i].second;
			for (int j = 0; j < i; ++j) {
				double d = dist(pos[i], pos[j]);
				if (d <= 10.0) adj[i][j] = adj[j][i] = d;
			}
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		double sol = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j) {
					sol = max(sol, adj[i][j]);
				}
			
		cout << "Case #" << ++ncase << ":" << endl;
		if (sol >= INF) cout << "Send Kurdy" << endl;
		else cout << fixed << sol << endl;
		cout << endl;
	}	
}