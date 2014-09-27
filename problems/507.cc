#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	int cases, ncase = 0;
	scanf("%d", &cases);
	while (cases--) {
		int n; scanf("%d", &n);
		int ml = 1, mr = 1, m = 0, tl = 1, t = 0;
		for (int i = 1; i < n; ++i) {
			int k; scanf("%d", &k);
			t += k;
			if (t > m or (t >= m and tl == ml)) {
				m = t;
				ml = tl;
				mr = i+1;
			}
			else if (t < 0) {
				tl = i+1;
				t = 0;
			}
		}
		if (m) printf("The nicest part of route %d is between stops %d and %d\n", ++ncase, ml, mr);
		else printf("Route %d has no nice parts\n", ++ncase);
	}
}