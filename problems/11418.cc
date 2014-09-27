#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

int s, t, f, INF = 1e9;
Vi p;
Mi res;

void augment(int v, int minEdge) {
	int u = p[v];
	if (v == s) f = minEdge;
	else if (u != -1) {
		augment(u, min(minEdge, res[u][v]));
		res[u][v] -= f;
		res[v][u] += f;
	}
}

int fn(string st) {
	return st[0] - 'A';
}

void tr(string &st) {
	if (st[0] >= 'a' and st[0] <= 'z') st[0] += 'A'-'a';
	for (int i = 1; i < st.size(); ++i)
		if (st[i] >= 'A' and st[i] <= 'Z') st[i] += 'a'-'A';
}

int main() {
	int T; cin >> T;
	int ncase = 0;
	while (T--) {
		int n; cin >> n;
		int left = 1;
		int right = left+n;
		s = 0;
		t = right + n;
		int total = t+1;
		res = Mi(total, Vi(total, 0));
		Mi adj(total);
		Ms names(n, Vs(26));
		p.assign(total, -1);

		for (int i = 0; i < n; ++i) {
			int k; cin >> k;
			names[i] = Vs(k);
			for (int j = 0; j < k; ++j) {
				string st; cin >> st;
				tr(st);
				names[i][fn(st)] = st;
				int x = fn(st);
				if (x < n) {
					res[1+x][right+i] = INF;
					adj[1+x].push_back(right+i);
					adj[right+i].push_back(1+x);
				}
				
			}
		}

		for (int i = left; i < left+n; ++i) {
			res[s][i] = 1;
			adj[s].push_back(i);
			adj[i].push_back(s);
		}

		for (int i = right; i < right+n; ++i) {
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
						dist[v] = dist[u]+1;
						q.push(v);
					}
				}
			}
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}

		cout << "Case #" << ++ncase << ':' << endl;

		for (int i = left; i < right; ++i) {
			for (int j = 0; j < adj[i].size(); ++j) {
				int k = adj[i][j];
				if (k != s and res[k][i] > 0) {

					cout << names[k-right][i-left] << endl;
				}					
			}
		}
	}
}