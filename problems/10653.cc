#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const int INF = 1000000000;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m),(n||m)) {
		vvi map(n, vi(m, INF));
		int nbombs; scanf("%d", &nbombs);
		while (nbombs--) {
			int row, nperrow; scanf("%d %d", &row, &nperrow);
			while (nperrow--) {
				int col; scanf("%d", &col);
				map[row][col] = -1; //bomb
			}
		}
		int sr, sc, dr, dc;
		scanf("%d %d %d %d", &sr, &sc, &dr, &dc);
		map[sr][sc] = 0;
		queue<ii> q;
		q.push(ii(sr,sc));
		int dist;
		while(!q.empty()) {
			ii u = q.front(); q.pop();
			if (u.first == dr and u.second == dc) {
				dist = map[u.first][u.second];
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int ti = u.first+di[i], tj = u.second+dj[i];
				if (ti >= 0 and ti < n and tj >= 0 and tj < m and map[ti][tj] == INF) {
					map[ti][tj] = map[u.first][u.second] +1;
					q.push(ii(ti,tj));
				}
			}
		}
		printf("%d\n", dist);
	}
}