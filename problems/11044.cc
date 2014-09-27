#include <cstdio>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		n-=2;
		m-=2;
		printf("%d\n", (n/3+(n%3>0))*(m/3+(m%3>0)));
	}
}