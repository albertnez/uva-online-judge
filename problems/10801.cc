#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> pi;
typedef vector<pi> Vpi;
typedef vector<Vpi> Mpi;
typedef vector<Mpi> Tpi;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
const int INF = 1e9;
int main() {
	int n, k;
	while (cin >> n >> k) {
		Vi T(n);
		Tpi adj(100, Mpi(n));
		for (int i = 0; i < n; ++i) cin >> T[i];
		cin.ignore();
		for (int i = 0; i < n; ++i) {
			string s;
			getline(cin, s);
			istringstream ss(s);
			int x;
			int pre = -1;
			while (ss >> x) {
				if (pre >= 0) {
					adj[pre][i].push_back(pi(T[i]*(x-pre), ii(x, i)));
					adj[x][i].push_back(pi(T[i]*(x-pre), ii(pre, i)));
			 	}
				for (int j = 0; j < n; ++j) if (j != i and adj[x][j].size() > 0) {
					adj[x][i].push_back(pi(60, ii(x, j)));
					adj[x][j].push_back(pi(60, ii(x, i)));
				}
				pre = x;
			}
		}

		Mi dist(100, Vi(n, INF));
		priority_queue<pi, Vpi, greater<pi> > pq; 
		for (int i = 0; i < n; ++i) if (adj[0][i].size() > 0) {
			dist[0][i] = 0;
			pq.push(pi(0, ii(0, i)));
		}
		bool found = false;
		int sol = -1;
		while (!pq.empty() and !found) {
			int d = pq.top().first;
			ii x = pq.top().second;
			pq.pop();

			if (x.first == k) {
				found = true;
				sol = d;
			}
			if (d > dist[x.first][x.second])
				continue;
			

			for (int i = 0; i < adj[x.first][x.second].size(); ++i) {
				pi tmp = adj[x.first][x.second][i];
				int nd = tmp.first;
				ii y = tmp.second;
				if (d+nd < dist[y.first][y.second]) {
					dist[y.first][y.second] = d+nd;
					pq.push(pi(d+nd, ii(y.first, y.second)));
				}
			}
		}
		if (sol == -1) cout << "IMPOSSIBLE" << endl;
		else cout << sol << endl;
	}
}