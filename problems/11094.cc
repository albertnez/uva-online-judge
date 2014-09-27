#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

//int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

int m, n;

bool land;

int dfs(int i, int j, vvb& map) {
	int sum = 1;
	for (int k = 0; k < 4; ++k) {
		int ti = i+di[k];
		int tj = (j+dj[k]+n)%n;
		if (ti >= 0 and ti < m and map[ti][tj] == land) {
			map[ti][tj] = !land;
			sum += dfs(ti,tj,map);
		}
	}
	return sum;
}

int main() {
	while (cin >> m >> n) {
		bool first = true;
		char fc;
		vvb map(n, vb(m, 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				char c; cin >> c;
				if (first) {
					fc = c;
					first = false;
				}
				map[i][j] = (c == fc);
			}
		}

		int x,y; cin >> x >> y;
		land = map[x][y];
		map[x][y] = !land;
		dfs(x,y,map);

		int maxim = 0, t = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == land) {
					map[i][j] = !land;
					maxim = max(maxim, dfs(i,j,map));
				}
			}
		}
		cout << maxim << endl;
	}
}