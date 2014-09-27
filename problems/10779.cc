#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int s, t, f;
Mi res;
Vi p;

const int INF = 1e9;


void augment(int u, int minEdge) {
	int v = p[u];
	if (u == s) {
		f = minEdge;
	}
	else if (v != -1) {
		augment(v, min(minEdge, res[v][u]));
		res[v][u] -= f;
		res[u][v] += f;
	}
}

int main() {
	int ncase = 0, T; cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		

		int istick = 1, nstick = m;
		int ifriend = istick + nstick, nfriend = n-1;
		int total = ifriend+nfriend+1;

		s = 0;
		t = total-1;

		res = Mi(total, Vi(total, 0));
		Mi adj(total);
		p.assign(total, -1);

		//source to stick
		int num; cin >> num;
		for (int i = 0; i < num; ++i) {
			int k; cin >> k;
			if (res[s][k] == 0) {
				adj[s].push_back(k);
				adj[k].push_back(s);
			}
			++res[s][k];
		}

		// stick to friend
		for (int i = 0; i < nfriend; ++i) {
			cin >> num;
			Vi rep(nstick+1, 0);
			for (int j = 0; j < num; ++j) {
				int k; cin >> k;
				++rep[k];
			}
			for (int j = istick; j < ifriend; ++j) {
				if (!rep[j]) {
					res[j][ifriend+i] = 1;
					adj[j].push_back(ifriend+i);
					adj[ifriend+i].push_back(j);
				}
				else if (rep[j] > 1) {
					res[ifriend+i][j] = rep[j]-1;
					adj[j].push_back(ifriend+i);
					adj[ifriend+i].push_back(j);
				}
			}
		}

		//stick to sink
		for (int i = istick; i < ifriend; ++i) {
			res[i][t] = 1;
			adj[i].push_back(t);
			adj[t].push_back(i);
		}


		int mf = 0;
		while (1) {
			queue<int> q;
			Vi dist(total, INF);
			dist[s] = 0;
			q.push(s);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int i = 0; i < adj[u].size(); ++i) {
					int v = adj[u][i];
					if (dist[v] == INF and res[u][v] > 0) {
						p[v] = u;
						dist[u] = dist[v]+1;
						q.push(v);
					}
				}
			}
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}

		cout << "Case #" << ++ncase << ": " << mf << endl;
	}
}