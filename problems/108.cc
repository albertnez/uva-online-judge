#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int mat[105][105];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			scanf("%d", &mat[i][j]);
			if (i > 0) mat[i][j] += mat[i-1][j];
			if (j > 0) mat[i][j] += mat[i][j-1];
			if (i > 0 and j > 0) mat[i][j] -= mat[i-1][j-1];
		}

	int maxim = -127*100*100;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		for (int k = i; k < n; ++k) for (int l = j; l < n; ++l) {
			int val = mat[k][l];
			if (i > 0) val -= mat[i-1][l];
			if (j > 0) val -= mat[k][j-1];
			if (i > 0 and j > 0) val += mat[i-1][j-1];
			maxim = max(maxim, val);
		}

	printf("%d\n", maxim);
}