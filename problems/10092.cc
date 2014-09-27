#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;


Mi res;
int s, t, INF = 1e9, f;
Vi p;


void augment(int v, int minEdge) {
	int u = p[v];
	if (v == s) f = minEdge;
	else if (u != -1) {
		augment(u, min(minEdge, res[u][v]));
		res[u][v] -= f;
		res[v][u] += f;
	}
}

int main() {
	int n, m;
	while (cin >> n >> m and (n|m)) {
		int total = n+m+2;
		s = 0, t = total-1;
		res = Mi(total, Vi(total, 0));
		Mi adj(total);
		p = Vi(total, -1);

		int req = 0;
		for (int i = 1; i <= m; ++i) {
			res[s][i] = 1;
			adj[s].push_back(i);
			adj[i].push_back(s);
		}

		for (int i = 0; i < n; ++i) {
			cin >> res[t-n+i][t];
			req += res[t-n+i][t];
			adj[t-n+i].push_back(t);
			adj[t].push_back(t-n+i);
		}

		for (int i = 1; i <= m; ++i) {
			int k; cin >> k;
			for (int j = 0; j < k; ++j) {
				int q; cin >> q; --q;
				res[i][t-n+q] = INF;
				adj[i].push_back(t-n+q);
				adj[t-n+q].push_back(i);
			}
		}	

		int mf = 0;
		while (1) {
			queue<int> q;
			Vi dist(total, INF);
			dist[s] = 0;
			q.push(0);

			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int i = 0; i < adj[u].size(); ++i) {
					int v = adj[u][i];
					if (res[u][v] > 0 and dist[v] == INF) {
						dist[v] = dist[u]+1;
						p[v] = u;
						q.push(v);
					}
				}
			}

			f = 0;
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}

		if (mf != req) cout << 0 << endl;
		else {
			cout << 1 << endl;
			for (int i = m+1; i < m+1+n; ++i) {
				bool first = true;
				for (int k = 0; k < adj[i].size(); ++k) {
					int j = adj[i][k];
					if (res[i][j] > 0 and j != t) {
						if (first) first = false;
						else cout << ' ';
						cout << j;
					}
				}
				cout << endl;
			}
		}


	}
}