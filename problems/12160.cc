#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> VI;
const int mod = 10000;

int main() {
	int l, u, r, ncase = 0;
	while (cin >> l >> u >> r and (l|u|r)) {
		VI v(r);
		for (int i = 0; i < r; ++i) cin >> v[i];

		VI dist(10000, -1);
		dist[l] = 0;
		queue<int> q;
		q.push(l);
		int sol = -1;
		while (!q.empty() and sol < 0) {
			int x = q.front(); q.pop();
			if (x == u) sol = dist[x];
			else {
				for (int i = 0; i < r; ++i) {
					int y = (x+v[i])%mod;
					if (dist[y] == -1) {
						q.push(y);
						dist[y] = dist[x]+1;
					}
				}
			}
		}
		cout << "Case " << ++ncase << ": ";
		if (sol == -1) cout << "Permanently Locked" << endl;
		else cout << sol << endl;
	}
}