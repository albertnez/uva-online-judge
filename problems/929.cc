#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> pi;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

const int INF = 1000000000;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, m;
		scanf("%d %d", &n, &m);
		Mi map(n, Vi(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &map[i][j]);
			}
		}
		Mi dist(n, Vi(m, INF));
		dist[0][0] = map[0][0];
		priority_queue<pi, vector<pi>, greater<pi> > q;
		q.push(pi(dist[0][0], ii(0,0)));
		while (!q.empty()) {
			int d = q.top().first;
			ii u = q.top().second; q.pop();
			if (d > dist[u.first][u.second]) continue;
			if (u == ii(n-1, m-1)) {
				printf("%d\n", dist[u.first][u.second]);
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int ti = u.first+di[i], tj = u.second+dj[i];
				if (ti >= 0 and ti < n and tj >= 0 and tj < m and d + map[ti][tj] < dist[ti][tj]) {
					dist[ti][tj] = d+map[ti][tj];
					q.push(pi(dist[ti][tj], ii(ti, tj)));

				}
			}
		}
	}
}