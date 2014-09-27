#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;

int main() {
	int T; cin >> T;
	int ncase = 0;
	while (T--) {
		int n, d;
		cin >> n >> d;
		VI v(n), s(n, 0);
		for (int i = 0; i < n; ++i) {
			char c; cin >> c;
			s[i] = c == 'S';
			cin >> c;
			cin >> v[i];
		}
		int max = 0;
		
		for (int it = 0; it < 2; ++it) {
			int prev = 0;
			int sk = it;
			for (int i = 0; i < n; ++i) {
				if (s[i]) {
					if (sk) {
						sk = 0;
						continue;
					}
					else sk = 1;
				}
				int x = v[i]-prev;
				if (x > max) max = x;
				prev = v[i];
			}
			int x = d-prev;
			if (x > max) max = x;
		}
		cout << "Case " << ++ncase << ": " << max << endl;
	}
}