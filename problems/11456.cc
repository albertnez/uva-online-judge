#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n; scanf("%d", &n);
		vector<int> v(n), lis(n, 1), lds(n, 1);
		int maxim = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = n-1; i >= 0; --i) {
			for (int j = i+1; j < n; ++j) {
				if (v[i] < v[j]) lis[i] = max(lis[i], lis[j]+1);
				if (v[i] > v[j]) lds[i] = max(lds[i], lds[j]+1);
			}
			maxim = max(maxim, lds[i]+lis[i]-1);
		}

		printf("%d\n", maxim);
	}
}