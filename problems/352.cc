#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi map;

int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;

void dfs(int i, int j) {
	map[i][j] = 0;
	for (int k = 0; k < 8; ++k) {
		int ti = i+di[k], tj = j+dj[k];
		if (ti >= 0 and ti < n and tj >= 0 and tj < n and map[ti][tj]) {
			dfs(ti,tj);
		}
	}

}

int main() {
	int cases = 0;
	while (cin >> n) {
		map = vvi(n, vi(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				char c; cin >> c;
				map[i][j] = c == '1';
			}

		int count = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j]) {
					++count;
					dfs(i, j);
				}
			}
		}
		cout << "Image number " << ++cases << " contains " << count << " war eagles." << endl;
	}
}