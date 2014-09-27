#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mi = 99, ma = 0, k;
		for (int i = 0; i < n; ++i) {
			cin >> k;
			mi = min(mi, k);
			ma = max(ma, k);
		}
		cout << 2*(ma - mi)*(n>1) << endl;
	}
}