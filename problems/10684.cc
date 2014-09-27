#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		int m = 0, sum = 0;
		while (n--) {
			int k; scanf("%d", &k);
			sum += k;
			m = max(m, sum);
			sum = max(sum, 0);
		}
		if (m) printf("The maximum winning streak is %d.\n", m);
		else printf("Losing streak.\n");
	}
}