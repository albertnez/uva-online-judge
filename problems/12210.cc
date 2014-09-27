#include <iostream>
using namespace std;
int main() {
	int n, m, ncase = 0;
	while (cin >> n >> m and (n|m)) {
		int min = 60;
		for (int i = 0; i < n; ++i) {
			int k; cin >> k;
			if (k < min) min = k;
		}
		for (int i = 0; i < m; ++i) {
			int k; cin >> k;
		}
		cout << "Case " << ++ncase << ": ";
		if (n > m) cout << n-m << ' ' << min << endl;
		else cout << 0 << endl; 
	}
}