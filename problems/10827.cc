#include <cstdio>
#include <algorithm>
using namespace std;

int m[155][155];

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int k; scanf("%d", &k);
				m[i][j] = m[n+i][j] = m[i][n+j] = m[n+i][n+j] = k;
			}
		}

		for (int i = 0; i < 2*n; ++i) {
			for (int j = 0; j < 2*n; ++j) {
				if (i > 0) m[i][j] += m[i-1][j];
				if (j > 0) m[i][j] += m[i][j-1];
				if (i > 0 and j > 0) m[i][j] -= m[i-1][j-1];
			}
		}

		// now maximum;
		int maximum = -1e9;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
			for (int k = i; k < i+n; ++k) for (int l = j; l < j+n; ++l) {
				int sum = m[k][l];
				if (i > 0) sum -= m[i-1][l];
				if (j > 0) sum -= m[k][j-1];
				if (i > 0 and j > 0) sum += m[i-1][j-1];
				maximum = max(maximum, sum);
			}

		printf("%d\n", maximum);
	}
}