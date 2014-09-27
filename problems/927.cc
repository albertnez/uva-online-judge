#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
typedef vector<int> Vi;
int main() {
	int c; cin >> c;
	while (c--) {
		int n; cin >> n;
		Vi p(n+1);
		for (int i = 0; i <= n; ++i) cin >> p[i];
		int d, k; cin >> d >> k;
		int q = 0, j = 0;
		while (q < k) {
			++j;
			q += d*j;
		}
		ll pot = 1, sum = 0;
		for (int i = 0; i <= n; ++i) {
			sum += pot*ll(p[i]);
			pot *= ll(j);
		}
		cout << sum << endl;
	}
}