#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;

int main() {
	int n, cas = 0;
	while (cin >> n and n) {
		Vi v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int m; cin >> m;

		cout << "Case " << ++cas << ':' << endl;
		while (m--) {
			int k; cin >> k;
			int closest = v[0]+v[1];
			for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
				int q = v[i] + v[j];
				if (abs(q-k) < abs(closest-k))
					closest = q;
			}
			cout << "Closest sum to " << k << " is " << closest << '.' << endl;
		}
	}
}