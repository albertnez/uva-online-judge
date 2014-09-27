#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int map[105][105];

int main() {
	int n, m; 
	while (scanf("%d %d", &n, &m), (n||m)) {
		for (int i = 0; i < n; ++i)	for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
			map[i][j] = 1-map[i][j];
			if (i > 0) map[i][j] += map[i-1][j];
			if (j > 0) map[i][j] += map[i][j-1];
			if (j > 0 and i > 0) map[i][j] -= map[i-1][j-1];
		}


		int maxim = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
			for (int k = i; k < n; ++k) for (int l = j; l < m; ++l) {
				int val = map[k][l];
				if (i > 0) val -= map[i-1][l];
				if (j > 0) val -= map[k][j-1];
				if (i > 0 and j > 0) val += map[i-1][j-1];
				if (val == (k-i+1)*(l-j+1))
					maxim = max(maxim, val);
			}

		printf("%d\n", maxim);
	}
}