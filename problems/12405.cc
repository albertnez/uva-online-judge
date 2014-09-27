#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, ncase = 0; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<bool> v(n);
		for (int i = 0; i < n; ++i) {
			char c; cin >> c;
			v[i] = c == '.';
		}
		int t = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				++t;
				for (int j = i; j < n and j < i+3; ++j)
					v[j] = false;
			}
		}
		cout << "Case " << ++ncase << ": " << t << endl;
	}
}