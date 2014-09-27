#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
int main() {
	int n, m;
	while (cin >> n >> m and (n|m)) {
		Vi h(n), k(m);
		for (int i = 0; i < n; ++i) cin >> h[i];
		for (int i = 0; i < m; ++i) cin >> k[i];
		sort(h.begin(), h.end());
		sort(k.begin(), k.end());
		int i = 0, j = 0;
		int t = 0;
		while (i < n and j < m) {
			if (h[i] <= k[j]) {
				t+=k[j];
				++i;
			}
			++j;
		}
		if (i == n) cout << t << endl;
		else cout << "Loowater is doomed!" << endl;
	}	
}