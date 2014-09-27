#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;
int main() {
	int T, ncase = 0;
	cin >> T;
	while (T--) {
		int r, c, m, n;
		cin >> r >> c >> m >> n;
		int di[8] = {m, m, n, n, -m, -m, -n, -n};
		int dj[8] = {n, -n, m, -m, n, -n, m, -m};
		VVI map(r, VI(c,0));
		int w; cin >> w;
		while (w--) {
			int i, j; cin >> i >> j;
			map[i][j] = -1;
		}

		int odd = 0, even = 0;
		queue<ii> q;
		q.push(ii(0,0));
		map[0][0] = 1;
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			int t = 0;
			for (int k = 0; k < 8; ++k) {
				int ti = i+di[k], tj = j+dj[k];
				if (ti < 0 or ti >= r or tj < 0 or tj >= c) continue;
				if (map[ti][tj] != -1) ++t;
				if (!map[ti][tj]) {
					q.push(ii(ti, tj));
					map[ti][tj] = 1;
				}

			}
			if (m==n or m==0 or n == 0) t/=2;
			if (t&1) ++odd;
			else ++even;
		}
		cout << "Case " << ++ncase << ": " << even << ' ' << odd << endl;
	}
}