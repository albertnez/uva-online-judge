#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
int main() {
	int cases, ncase = 0; scanf("%d", &cases);
	while (cases--) {
		int n; scanf("%d", &n);
		Vi w(n), h(n), lis(n), lds(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &h[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &w[i]);


		int mlis = 0, mlds = 0;
		for (int i = 0; i < n; ++i) {
			lis[i] = lds[i] = w[i];
			for (int j = 0; j < i; ++j) {
				if (h[j] < h[i]) lis[i] = max(lis[i], lis[j]+w[i]);
				if (h[j] > h[i]) lds[i] = max(lds[i], lds[j]+w[i]);
			}
			mlis = max(mlis, lis[i]);
			mlds = max(mlds, lds[i]);
		}
		if (mlis >= mlds) printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++ncase, mlis, mlds);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++ncase, mlds, mlis);
	}
}