#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;
vvc map;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int n;

bool dfs(int i, int j) {
	bool b = (map[i][j] == 'x');
	map[i][j] = '.';
	for (int k = 0; k < 4; ++k) {
		int ti = i+di[k], tj = j+dj[k];
		if (ti >= 0 and ti < n and tj >= 0 and tj < n and map[ti][tj] != '.' and dfs(ti, tj)) b = true;
	}
	return b;
}

int main() {
	int cases = 0;
	int k; cin >> k;
	while (k--) {
		while (cin >> n) {
			map = vvc(n, vc(n));
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					cin >> map[i][j];
			int t = 0;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (map[i][j] != '.') {
						t += dfs(i,j);
					}
				}
			}
			cout << "Case " << ++cases << ": " << t << endl;
		}
	}
}