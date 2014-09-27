#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> pi;
typedef vector<pi> Vpi;
typedef vector<Vpi> VVpi;

typedef vector<int> Vi;
typedef vector<Vi> VVi;

const int INF = 1e9;
int main() {
	int m; 
	while (cin >> m and m) {
		int count = 2;
		map<string,int> msi;
		//start = 0, end = 0;
		string s;
		cin >> s; msi[s] = 0;
		cin >> s; msi[s] = 1;

		VVpi adj(m*2+2);
		for (int i = 0; i < m; ++i) {
			string a, b, c; cin >> a >> b >> c;
			if (msi.find(a) == msi.end()) msi[a] = count++;
			if (msi.find(b) == msi.end()) msi[b] = count++;
			int ch = c[0]-'a', sz = c.size();
			adj[msi[a]].push_back(pi(sz, ii(msi[b], ch)));
			adj[msi[b]].push_back(pi(sz, ii(msi[a], ch)));
		}
		priority_queue<pi, Vpi, greater<pi> > pq;
		VVi dist(m*2+2, Vi(26, INF));
		dist[0][0] = 0;
		pq.push(pi(0, ii(0,0)));
		bool found = false;
		int sol = -1;
		while (!pq.empty() and !found) {
			int d = pq.top().first;
			ii pos = pq.top().second;
			int u = pos.first;
			pq.pop();

			if (u == 1) {
				sol = d;
				found = true;
			} 
			else if (d <= dist[u][pos.second]) {
				for (int i = 0; i < adj[u].size(); ++i) if (adj[u][i].second.second != pos.second or u == 0) {
					int nd = adj[u][i].first;
					ii tmp = adj[u][i].second;

					if (nd+d < dist[tmp.first][tmp.second]) {
						dist[tmp.first][tmp.second] = nd+d;
						pq.push(pi(nd+d, ii(tmp.first, tmp.second)));
					}
				}
			}
		}

		if (sol == -1) cout << "impossivel" << endl;
		else cout << sol << endl;
	}
}