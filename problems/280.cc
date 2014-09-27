#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;


int INF = 1e9;
int main() {
	int n;
	while (cin >> n and n) {
		Mi adj(n);
		int s;
		while (cin >> s and s) {
			int k;
			while (cin >> k and k)
				adj[s-1].push_back(k-1);
		}
		int num; cin >> num;
		while (num--) {
			int k; cin >> k;

			queue<int> q;
			Vi dist(n, INF);
			q.push(k-1);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int i = 0; i < adj[u].size(); ++i) {
					int v = adj[u][i];
					if (dist[v] == INF) {
						dist[v] = dist[u]+1;
						q.push(v);
					}
				}
			}
			bool first = true;
			int sol = 0;
			for (int i = 0; i < n; ++i) sol += dist[i] == INF;
			cout << sol;
			for (int i = 0; i < n; ++i)
				if (dist[i] == INF)
					cout << ' ' <<i+1;

			cout << endl;

		}
	}
}