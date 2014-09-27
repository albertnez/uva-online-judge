#include <iostream>
using namespace std;
int main() {
	int n,b,h,w;
	while (cin >> n >> b >> h >> w) {
		int min = b+1;
		while (h--) {
			int p;
			cin >> p;
			int tmp = p*n;
			bool ok = false;
			for (int i = 0; i < w; ++i) {
				int r; cin >> r;
				if (r >= n) ok = true;
			}
			if (ok and tmp < min) min = tmp;
		}
		if (min <= b) cout << min << endl;
		else cout << "stay home" << endl;
	}
}