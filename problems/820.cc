#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

// FLOW WITH DINICS ALGORITHM




/*
 ************************
 EDMONDS KARP ALGORITHM
 ************************
const int INF = 1e9;

int s, f;
Mi res;
Vi p;
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}


int main() {
	int n, t, con, ncase = 0;
	while (cin >> n and n) {
		cin >> s >> t >> con;
		--s; --t;
		res = Mi(n, Vi(n, 0));
		Mi adj(n);
		p = Vi(n, -1);

		while (con--) {
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b;
			if (c > 0 and res[a][b] == 0) {
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			res[a][b] = res[b][a] += c;
		}

		int mf = 0;
		while (1) {
			f = 0;
			Vi dist(n, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int i = 0; i < adj[u].size(); ++i) {
					int v = adj[u][i];
					if (res[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u]+1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}
		cout << "Network " << ++ncase << endl << "The bandwidth is " << mf << '.' << endl << endl;
	}
}
*/